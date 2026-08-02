
# Memory Error Detectors — Notes

- **Author:** Yash Deshpande
- **Date:** 01-08-2026
- **LLM Model:** Claude (Opus 4.8)

## Sources

- [Valgrind tutorial](https://youtu.be/Sddn1UjzSAo?si=64pK9te6KxL-jbYY) — YouTube video by Jack Sorber
- [AddressSanitizer tutorial](https://youtu.be/tEbV21aPSKw?si=bWeLXZRKXdLItddI) — YouTube video by Jack Sorber
- [AddressSanitizer — leaks & use-after-free](https://youtu.be/_Al7Y7BI-ds?si=35mSs0L2xvP1Ru8D) — YouTube video by Jack Sorber

> **Disclaimer:** These notes survey all four families for completeness, but we will **focus only on Family 1 (dynamic binary instrumentation — Valgrind) and Family 2 (compiler-based sanitizers — ASan and friends)**. Families 3 (hardware-assisted) and 4 (guard-page / allocator-based) are included for context only and are not covered in depth.

## Index

1. [What is a memory error detector?](#what-is-a-memory-error-detector)
2. [The four families](#the-four-families)
3. [Family 1 — Dynamic binary instrumentation](#family-1--dynamic-binary-instrumentation)
4. [Family 2 — Compiler-based sanitizers](#family-2--compiler-based-sanitizers)
5. [Valgrind](#valgrind)
   - [How does Valgrind work?](#how-does-valgrind-work)
   - [Do we need `-g` (debug symbols) to compile?](#do-we-need--g-debug-symbols-to-compile)
6. [AddressSanitizer](#addresssanitizer)
   - [How does AddressSanitizer work?](#how-does-addresssanitizer-work)
7. [Valgrind vs ASan — what each uniquely catches](#valgrind-vs-asan--what-each-uniquely-catches)
8. [Family 3 — Hardware-assisted](#family-3--hardware-assisted)
9. [Family 4 — Guard-page / allocator-based](#family-4--guard-page--allocator-based)
10. [Comparison table](#comparison-table)
11. [Which to reach for, when](#which-to-reach-for-when)


## What is a memory error detector?

A **memory error detector** is a tool that watches a program's memory accesses and reports bugs the compiler and CPU won't catch on their own:

- **Buffer overflow / out-of-bounds** — reading or writing past the end of an array or heap block.
- **Use-after-free (UAF)** — accessing memory that has already been `free`d.
- **Use-after-return / use-after-scope** — using a pointer to a stack variable after its frame is gone.
- **Uninitialized reads** — reading memory before it was ever written.
- **Invalid / double free** — freeing a pointer twice, or one that wasn't heap-allocated.
- **Memory leaks** — heap memory that is never freed and never reachable at exit.

These are the classic C/C++ bugs: undefined behavior that may *appear* to work, corrupt data silently, or crash unpredictably. The tools below differ mainly in **how** they observe memory — which drives their speed, what they catch, and whether you must recompile.


## The four families

Detectors are grouped by their underlying mechanism:

1. **Dynamic binary instrumentation** — run the existing binary inside a virtual CPU (no recompile).
2. **Compiler-based sanitizers** — the compiler injects checks (recompile with `-fsanitize=...`).
3. **Hardware-assisted** — use CPU features (pointer tagging) for near-zero overhead.
4. **Guard-page / allocator-based** — swap the allocator so bad accesses trap immediately.


## Family 1 — Dynamic binary instrumentation

Runs your **already-compiled** binary inside a synthetic CPU and checks every load/store as it executes. No recompilation, but a heavy slowdown.

| Tool | Platform | Notes |
|------|----------|-------|
| **Valgrind (Memcheck)** | Linux, macOS | The classic. Detects leaks, UAF, uninitialized reads, invalid/double free, heap overflows. ~10–50x slowdown. |
| **Dr. Memory** | Linux, Windows | Same idea as Memcheck, generally faster; better Windows support. |

### Valgrind — key points

- **No recompile needed**, but compile with `-g` for line numbers in the report.
- Compile: `gcc -g my_prog.c`
- Run: `valgrind ./a.out`  (add `--leak-check=full` for per-leak detail).
- **Catches uninitialized reads** — something plain ASan does *not*.
- **Cost:** very slow (10–50x). Best for targeted debugging, not every test run.

See [`3_tool_valgrind.c`](./3_tool_valgrind.c) for a worked leak + overflow example.


## Family 2 — Compiler-based sanitizers

The compiler **instruments the code at build time** — it inserts shadow-memory bookkeeping and checks around memory operations. Much faster than Valgrind (~2x), but requires recompiling with the right `-fsanitize` flag. These ship with GCC and Clang.

| Sanitizer | Flag | Catches | Slowdown |
|-----------|------|---------|----------|
| **AddressSanitizer (ASan)** | `-fsanitize=address` | Heap/stack/global overflow, UAF, use-after-return/scope, double free | ~2x |
| **MemorySanitizer (MSan)** | `-fsanitize=memory` | Uninitialized memory reads (Clang only) | ~3x |
| **LeakSanitizer (LSan)** | `-fsanitize=leak` | Memory leaks (bundled inside ASan by default) | ~0 |
| **UndefinedBehaviorSanitizer (UBSan)** | `-fsanitize=undefined` | Null deref, misaligned pointers, integer overflow, bad shifts | small |
| **ThreadSanitizer (TSan)** | `-fsanitize=thread` | Data races (concurrent unsynchronized access) | ~5–15x |

### AddressSanitizer — key points

- Compile *and* run instrumented: `gcc -fsanitize=address -g my_prog.c && ./a.out`.
- Uses **shadow memory** — a compact map marking each byte as addressable or "poisoned" (redzones around allocations, freed blocks). Any access to poisoned memory is reported instantly with a stack trace.
- **Fast enough for everyday development** and CI test suites — the usual default.
- **Does not catch uninitialized reads** — that's MSan's job (they're mutually exclusive; you can't combine ASan + MSan in one build).
- Useful runtime knob: `ASAN_OPTIONS=detect_leaks=1` (Linux default on) / `halt_on_error=0`.

See [`6_tool_address_sanitizer.c`](./6_tool_address_sanitizer.c) and [`7_tool_address_sanitizer_2.c`](./7_tool_address_sanitizer_2.c) for worked overflow examples.

### Which sanitizers combine

- **ASan + UBSan + LSan** → common combined build (`-fsanitize=address,undefined`).
- **MSan** and **TSan** each need their *own* dedicated build — they can't share with ASan.


## Valgrind

Deep-dive notes on Valgrind (the Family 1 tool we focus on). See [`3_tool_valgrind.c`](./3_tool_valgrind.c) for a worked leak + overflow example.

### How does Valgrind work?

Valgrind isn't just Memcheck — it's a **framework** for building dynamic analysis tools. **Memcheck** (the memory error detector) is the default tool that runs on top of it. Others include Helgrind (data races), Cachegrind (cache profiling), and Massif (heap profiling).

#### Core idea: a synthetic CPU

Valgrind doesn't run your program directly on the real CPU. It runs it on a **software-emulated CPU**, watching every instruction as it executes. This is why it needs **no recompilation** (it works on the existing binary) and also why it's **slow** (10–50x).

#### The pipeline: dynamic binary translation

```
your binary → disassemble → IR → instrument → recompile → run
              (machine code)  (VEX)  (add checks)  (to host)
```

1. **Disassemble** — Valgrind reads your machine code in small **basic blocks**, just ahead of execution.
2. **Lift to IR** — it translates those instructions into an architecture-neutral intermediate representation called **VEX** (RISC-like, SSA form). This decouples the analysis from x86/ARM specifics.
3. **Instrument** — the active tool (Memcheck) inserts its *own* extra IR around each memory operation — the checking logic.
4. **Recompile & run** — the instrumented IR is compiled back to host machine code and executed. Translations are **cached** so hot blocks aren't re-translated.

Your program's logic runs unchanged; it just runs *through* this translate → instrument → execute loop.

#### What Memcheck adds: shadow memory

The heart of the detection. Memcheck keeps **shadow state** — a parallel bookkeeping copy of your memory that the real program never sees:

- **A (addressability) bits** — one bit per byte: "is this byte legal to access right now?" Heap redzones, freed blocks, and unallocated regions are marked invalid.
- **V (validity / defined) bits** — one bit per *bit* of data: "has this been initialized?"

On every access, the instrumented code checks the shadow state **before** letting it proceed:

| Bug | How the shadow catches it |
|-----|---------------------------|
| Buffer overflow | Access hits a byte whose **A-bit** says "not addressable" (a redzone around the block) |
| Use-after-free | `free()` flips the block's A-bits to invalid; a later access trips them |
| Uninitialized read | The **V-bits** say the value was never written, and it propagates into a branch/syscall |
| Invalid / double free | Freeing a pointer Memcheck's records say isn't a live block start |

#### How malloc/free are tracked

Memcheck **intercepts** `malloc`, `free`, `new`, `delete`, etc. It wraps each allocation with **redzones** (guard bytes marked non-addressable) and records the size + allocation stack trace. At exit, any block still recorded as allocated but no longer reachable is reported — that's the **leak check**.

#### Why the trade-offs fall out of this design

- **No recompile needed** → it instruments the binary at runtime, not the source. (`-g` only adds line numbers to reports — see below.)
- **Slow (10–50x)** → every instruction goes through translation + shadow checks.
- **Catches uninitialized reads** → thanks to per-bit V-bits, something ASan cannot do (that's MSan's niche).
- **Poor at data races** → Valgrind serializes threads onto its synthetic CPU (one at a time), so use Helgrind or TSan for concurrency bugs.

**One-line summary:** Valgrind JIT-translates your machine code into instrumented code that runs on a virtual CPU, while Memcheck shadows every byte's *addressability* and every bit's *definedness* to flag illegal or uninitialized accesses the instant they happen.

### Do we need `-g` (debug symbols) to compile?

**Short answer:** No — Valgrind runs on any binary. But you almost always *want* `-g`, because without it the reports point at raw addresses instead of your source lines.

#### What `-g` actually does

`-g` embeds **debug info** (DWARF) into the binary: source file names, line numbers, variable names, and the mapping from machine addresses back to source code. It's the same metadata `gdb` and `readelf --debug-dump` read — and the same info the [`binary_inspection`](../binary_inspection/binary_inspection_tools.md) notes saw *leaking* source paths and variable names into the binary. Valgrind simply consumes it for its stack traces.

#### Why detection doesn't need it

Valgrind works by **instrumenting memory accesses at runtime** inside its synthetic CPU. It sees an out-of-bounds write or a use-after-free *as it happens*, purely from the memory operation itself — it never needs your source to know the access was invalid. So the bug is caught either way; `-g` only affects how *readable* the report is.

#### The difference in the report

Without `-g` — you get the function name (from the symbol table) but **no line number**:

```
==191907== Invalid write of size 4
==191907==    at 0x1091A3: main (in /home/.../a.out)
```

With `-g` — you get the exact file and line:

```
==191907== Invalid write of size 4
==191907==    at 0x1091A3: main (3_tool_valgrind.c:21)
```

Line 21 is `myarray[i] = i;` — now the report is directly actionable.

| Build | Detects the bug? | Function name? | Line number? |
|-------|:---:|:---:|:---:|
| No `-g`   | ✅ | ✅ (unless stripped) | ❌ |
| With `-g` | ✅ | ✅ | ✅ |

#### Also avoid heavy optimization

Pair `-g` with `-O0` (no optimization) when debugging. At `-O2`/`-O3` the compiler inlines and reorders code, so even *with* `-g` the reported line numbers can be misleading. The debugging sweet spot is:

```bash
gcc -g -O0 my_prog.c
valgrind ./a.out
```

**Rule of thumb:** `-g` is optional for *detection*, essential for *readable reports*; `strip` throws this away, so debug on an unstripped `-g -O0` build.


## AddressSanitizer

Deep-dive notes on AddressSanitizer (ASan), the Family 2 tool we focus on. See [`6_tool_address_sanitizer.c`](./6_tool_address_sanitizer.c) and [`7_tool_address_sanitizer_2.c`](./7_tool_address_sanitizer_2.c) for worked overflow examples.

### How does AddressSanitizer work?

ASan takes the **opposite** approach to Valgrind: instead of a synthetic CPU watching an unmodified binary, the **compiler bakes the checks into your code at build time**. That's why it's ~2x (not 10–50x) but requires recompilation.

#### Two halves: compile-time instrumentation + a runtime library

1. **Instrumentation** — with `-fsanitize=address`, the compiler injects a check before **every** memory load/store.
2. **Runtime library** — a replacement allocator plus the shadow-memory machinery, linked in automatically.

#### The core mechanism: shadow memory (different from Valgrind)

ASan splits the address space into two regions:

- **Application memory** — where your program's data lives.
- **Shadow memory** — a compact map describing the "poisoned" status of application memory.

The trick is a fixed **8-to-1 compression**. Every aligned **8-byte** chunk of application memory maps to **1 byte** of shadow memory:

```
shadow_address = (app_address >> 3) + offset
```

That `>> 3` (divide by 8) plus add-offset is only a couple of instructions — cheap, which is why ASan is fast compared to Valgrind's per-access shadow lookups.

#### What the shadow byte encodes

Because 8 bytes → 1 shadow byte, and accesses often touch only a prefix of those 8:

- `0` → all 8 bytes are **addressable** (good).
- `1`–`7` → only the first *k* bytes are addressable (a partial redzone — e.g. a `char[5]` leaves 3 bytes poisoned).
- **negative** → all 8 bytes are **poisoned** (redzone, freed memory, etc.), with the specific value naming *why* (heap redzone, freed, stack-after-return…).

#### The injected check

Before a memory access, the compiler-inserted code does roughly:

```c
shadow = *(shadow_addr(ptr));
if (shadow != 0 && (ptr & 7) + access_size > shadow)
    __asan_report_error();   // print diagnostic + stack trace, abort
```

The fast path is a single shadow read + compare. Only when it looks poisoned does it fall into the slow reporting path.

#### Redzones: how it catches each bug

The runtime allocator surrounds every allocation with **poisoned redzones**:

```
[ redzone ][ your 32 bytes ][ redzone ]
  poisoned    addressable     poisoned
```

| Bug | How ASan catches it |
|-----|---------------------|
| **Heap overflow** | Access lands in the redzone → shadow is negative → report |
| **Stack overflow** | Compiler adds redzones around stack arrays too |
| **Global overflow** | Redzones placed around globals at link time |
| **Use-after-free** | `free()` **poisons** the whole block and parks it in *quarantine* (not immediately reused), so a later access still sees poison |
| **Use-after-return** | Stack frame's shadow is poisoned on return (`detect_stack_use_after_return`) |
| **Double free** | Freeing an already-quarantined/poisoned block is flagged |

The **quarantine** is key for use-after-free: freed memory is held aside for a while instead of instantly recycled, so dangling-pointer accesses reliably hit poison rather than valid new data.

#### ASan vs Valgrind — same concept, different engineering

| | Valgrind (Memcheck) | AddressSanitizer |
|---|---|---|
| When checks are added | Runtime, via JIT translation | Compile time, by the compiler |
| Recompile? | No | Yes (`-fsanitize=address`) |
| Speed | 10–50x | ~2x |
| Shadow granularity | per byte (A-bits) + per bit (V-bits) | 8 bytes → 1 shadow byte |
| Uninitialized reads | ✅ caught | ❌ (that's MSan) |
| Mechanism | emulates the CPU | native code + injected checks |

**One-line summary:** ASan makes the compiler wrap every allocation in poisoned redzones and inject a one-instruction shadow-memory check before each access, so out-of-bounds and use-after-free hits land in poisoned shadow and abort instantly — trading a required recompile for far lower overhead than Valgrind.


## Valgrind vs ASan — what each uniquely catches

Valgrind and ASan overlap heavily, but each has a real blind spot the other covers. They are **complementary, not redundant**.

### Valgrind catches, but ASan does NOT

| Error | Why ASan misses it |
|-------|--------------------|
| **Uninitialized memory reads** | The big one. Reading a `malloc`'d-but-never-written value (or an uninitialized stack variable) and *using* it in a branch/syscall/output. ASan tracks only *addressability* (is this byte legal?), not *definedness* (was it written?). Valgrind's per-bit **V-bits** track this; in the sanitizer world you need **MSan** instead. |
| **Uninitialized values propagating** | Valgrind follows undefined values through copies until they actually affect behavior, then reports the origin. |
| **Bad syscall parameters** | Passing an uninitialized or unaddressable buffer to a system call — Valgrind checks syscall arguments; ASan doesn't intercept these. |
| **Bugs in non-instrumented code** | Valgrind runs on the *final binary*, so it also checks **third-party libraries, precompiled `.so`s, and code you can't recompile**. ASan only sees code built with `-fsanitize=address` — bugs inside an uninstrumented library are invisible. |
| **Leak classification** | Both find leaks, but Valgrind classifies them (definitely / indirectly / possibly lost, still reachable) with no rebuild. |

### ASan catches, but Valgrind does NOT (or does poorly)

| Error | Why Valgrind misses it |
|-------|------------------------|
| **Stack buffer overflow** | The big one in reverse. ASan puts redzones around **stack arrays** (`char buf[10]; buf[10]=...`). Valgrind only instruments heap allocations, so out-of-bounds on a local array usually goes undetected. |
| **Global buffer overflow** | ASan places redzones around **global/static arrays** at link time. Valgrind has no notion of global-variable bounds. |
| **Use-after-return** | Accessing a pointer to a local after its function returned (`detect_stack_use_after_return`). Valgrind can't track stack-frame lifetimes this way. |
| **Use-after-scope** | Using a variable after its `{ }` block ended, even in the same function. A purely compile-time-known bound Valgrind has no visibility into. |
| **Intra-object overflow** | Because ASan knows source-level layout, it can catch overflows *within* a struct/stack frame that the raw binary hides. |

### Why the split exists — root cause

It follows directly from *how each works*:

- **Valgrind** operates on the **finished binary** at runtime → sees *all* code (even libraries) and can shadow every bit for definedness → wins on **uninitialized reads** and **uninstrumented code**. But the binary has erased stack/global bounds → **blind to stack/global overflows**.
- **ASan** is injected by the **compiler**, which still knows source-level layout → guards **stack arrays, globals, scopes, and returns**. But it sees only recompiled code and tracks addressability, not definedness → **blind to uninitialized reads and library-internal bugs**.

### The shared overlap

Both reliably catch **heap buffer overflow**, **heap use-after-free**, and **double free** — reach for either for those.

**Practical takeaway:** run **ASan** in day-to-day dev/CI (fast; stack + global + heap + UAF/UAR), add **MSan** to cover uninitialized reads (ASan's gap), and reach for **Valgrind** when you can't recompile, need library-internal coverage, or want rich leak classification.


## Family 3 — Hardware-assisted

Use CPU features to tag pointers/memory so checks cost almost nothing — cheap enough to leave on in **production**.

| Tool | Mechanism | Notes |
|------|-----------|-------|
| **HWASan** (Hardware-assisted ASan) | ARM64 **top-byte-ignore** — stores a tag in the unused high byte of each pointer | ~2x memory, low CPU; used in Android |
| **MTE** (Memory Tagging Extension) | ARMv8.5 hardware feature — tags 16-byte memory granules | Near-zero overhead; hardware must support it |
| **Intel MPX** | Hardware bounds registers | **Deprecated / removed** — dropped by Linux and GCC |

The idea: every allocation gets a small **tag**; the pointer carries the same tag. On each access the hardware compares pointer-tag vs memory-tag — a mismatch (overflow or UAF into differently-tagged memory) faults immediately. Overhead is low because the comparison is done in hardware, not injected code.


## Family 4 — Guard-page / allocator-based

Replace `malloc`/`free` with a debugging allocator that positions allocations so that a bad access hits a **protected page** and segfaults on the spot — turning silent corruption into an immediate, pinpointed crash.

| Tool | Mechanism | Notes |
|------|-----------|-------|
| **Electric Fence** (`efence`) | Places each allocation adjacent to an unmapped guard page | Overflow → instant segfault at the faulting instruction. Just link `-lefence`. High memory use. |
| **GWP-ASan** | Sampling — guards a *small random fraction* of allocations | Low overhead by design; catches rare bugs in production over time. |
| **glibc built-ins** | `MALLOC_CHECK_`, `mcheck()`, `_FORTIFY_SOURCE` | Lightweight heap consistency + compile-time buffer checks (`_FORTIFY_SOURCE=2` needs `-O1+`). |

The trade-off vs sanitizers: guard-page tools are simple and need no special build (just relink), but they only reliably catch **overflows that cross into the guard page** — they don't track uninitialized reads or give the rich diagnostics ASan/Valgrind do.


## Comparison table

| Tool | Recompile? | Speed | Leaks | Overflow | UAF | Uninit reads | Data races |
|------|-----------|-------|:-----:|:--------:|:---:|:------------:|:----------:|
| **Valgrind** | No | Slow (10–50x) | ✅ | ✅ | ✅ | ✅ | ❌ |
| **ASan** | Yes | ~2x | ✅ | ✅ | ✅ | ❌ | ❌ |
| **MSan** | Yes | ~3x | ❌ | ❌ | ❌ | ✅ | ❌ |
| **TSan** | Yes | ~5–15x | ❌ | ❌ | ❌ | ❌ | ✅ |
| **UBSan** | Yes | small | ❌ | partial | ❌ | ❌ | ❌ |
| **Electric Fence** | No (relink) | Fast | ❌ | ✅ (segfault) | ✅ | ❌ | ❌ |
| **HWASan / MTE** | Yes | Near-zero | ✅ | ✅ | ✅ | ❌ | ❌ |


## Which to reach for, when

| You want to...                                    | Use                          |
|---------------------------------------------------|------------------------------|
| Fast everyday dev + CI, catch most heap/stack bugs | **ASan** (`-fsanitize=address`) |
| Add uninitialized-read coverage                   | **MSan** (separate build)    |
| Debug without being able to recompile             | **Valgrind**                 |
| Deep leak detail out of the box                   | **Valgrind** (`--leak-check=full`) |
| Hunt data races in multithreaded code             | **TSan**                     |
| Catch UB (null deref, overflow, misalignment)     | **UBSan** (pairs with ASan)  |
| Near-zero-overhead checks in production            | **HWASan / MTE** (ARM64)     |
| Pinpoint an overflow to the exact faulting line   | **Electric Fence**           |

**Rule of thumb:** reach for **ASan** first — it's fast and catches the majority of memory bugs. Add **MSan** when you suspect uninitialized reads, **TSan** for concurrency bugs, and fall back to **Valgrind** when you can't recompile or want the richest leak report. Hardware-assisted tools (HWASan/MTE) are the production story; guard-page tools are the quick, no-build-change option.
