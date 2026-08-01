# Translation Units — Notes

- **Author:** Yash Deshpande
- **Date:** 31-07-2026
- **LLM Model:** Claude (Opus 4.8)

## TL;DR

- A **translation unit** = one `.cpp` file **after the preprocessor runs** (headers pasted in, macros expanded).
- It is the exact chunk of code the compiler processes at one time.
- Each `.cpp` → one TU → one `.o` object file (`g++ -c`).
- The **linker** then joins all the `.o` files into the final executable (`g++ *.o -o app`).
- Headers get pasted *into* a `.cpp` and never become their own `.o`.

## Index

- [What is a Translation Unit?](#what-is-a-translation-unit)
- [The Compilation Pipeline](#the-compilation-pipeline)
- [TU vs `.o` — Not the Same Thing](#tu-vs-o--not-the-same-thing)
- [Why it Matters](#why-it-matters)
- [Quick Example](#quick-example)
- [Walkthrough: the Example Step by Step](#walkthrough-the-example-step-by-step)
- [Compilation Commands (g++)](#compilation-commands-g)

## What is a Translation Unit?

A **translation unit (TU)** is the fundamental unit of compilation in C++ — it is the exact chunk of code the compiler processes at one time.

A translation unit is a **single source file (`.cpp`) after the preprocessor has run**, meaning:

```
Translation Unit = your .cpp file
                 + all #include'd headers (pasted in)
                 + macro expansions
                 + #ifdef branches resolved
```

The compiler never sees your raw `.cpp`. It sees the *preprocessed* result — one big stream of code — and that stream is the translation unit.

## The Compilation Pipeline

```
foo.cpp ──┐
          ├─► [Preprocessor] ─► Translation Unit ─► [Compiler] ─► foo.o ──┐
headers ──┘                                                               │
                                                                          ├─► [Linker] ─► executable
                                                                          │
                                                            bar.o ────────┘
```

Each `.cpp` becomes **one** TU → **one** object file (`.o`). The **linker** then stitches all the object files together into the final executable.

## TU vs `.o` — Not the Same Thing

They map **one-to-one**, so people often say "a `.o` *is* a TU." Strictly though, they are different stages:

- **TU** = the *input* — preprocessed *source code* the compiler reads.
- **`.o`** = the *output* — *compiled machine code* + symbol table the compiler produces from that TU.

```
.cpp  ──preprocess──►  Translation Unit  ──compile──►  .o
                       (source input)                 (compiled output)
```

### Cookie Dough Analogy

The TU is the **cookie dough**, the `.o` is the **baked cookie**.

- One ball of dough → one baked cookie (1 TU → 1 `.o`).
- They correspond one-to-one, but the baked cookie is **not** the dough — it has been *transformed* (source → machine code).

### Two Caveats to the 1:1 Mapping

1. **Headers are not separate TUs.** A `.h` gets *pasted into* a `.cpp`, so it becomes part of whichever TU includes it. There is no `.o` produced per header.
2. **Same file can make different TUs.** Compiling one `.cpp` twice with different flags (e.g. different `-D` macros) yields two *different* TUs → two *different* `.o` files, even though it is the same file on disk.

So: **`.o` count = TU count = number of `.cpp` files you actually compile** (not the number of headers).

## Why it Matters

| Concept | Connection to TU |
| --- | --- |
| **`static` / anonymous namespace** | Gives a symbol *internal linkage* — visible only within its own TU. |
| **ODR (One Definition Rule)** | A function/variable can be *defined* only once across all TUs (else linker error: "multiple definition"). |
| **`inline`** | Lets you define something in a header included by many TUs without violating the ODR. |
| **`extern`** | Declares a symbol that is *defined* in another TU. |
| **Include guards / `#pragma once`** | Prevent a header from being pasted twice into the *same* TU. |

## Quick Example

```cpp
// math.h
int square(int x);         // declaration

// math.cpp   <-- Translation Unit 1
#include "math.h"
int square(int x) { return x * x; }   // definition

// main.cpp   <-- Translation Unit 2
#include "math.h"
int main() { return square(5); }      // uses declaration
```

Two TUs → two `.o` files → linker connects `main`'s call to `square`'s definition.

## Walkthrough: the Example Step by Step

### What the preprocessor does

For `#include "math.h"` the preprocessor simply **deletes that line and pastes the entire contents of `math.h` in its place** — a plain copy-paste.

**`math.cpp` after preprocessing (Translation Unit 1):**

```cpp
int square(int x);                    // <-- pasted from math.h (declaration)
int square(int x) { return x * x; }   // <-- your definition
```

**`main.cpp` after preprocessing (Translation Unit 2):**

```cpp
int square(int x);                // <-- pasted from math.h (declaration)
int main() { return square(5); }  // uses square, but only knows its declaration
```

Note TU 2 has **no idea** what `square` actually does — it only has the *declaration* (the promise that `square` exists somewhere).

### How we get 2 different `.o` files

The compiler runs **once per `.cpp`**, and each run produces one `.o`:

| TU | Compiled to | Contains | Knows `square`'s body? |
| --- | --- | --- | --- |
| `math.cpp` (TU1) | `math.o` | machine code for `square` | yes — it *defines* it |
| `main.cpp` (TU2) | `main.o` | machine code for `main`, with an **unresolved reference** to `square` | no — just a "call square" placeholder |

Two separate `.cpp` files → two separate compiler runs → **two `.o` files**. The header is **not** compiled on its own — it has no `.o`; it just gets pasted into both TUs.

`main.o` has a **hole** where the call to `square` is — it knows the name and signature (from the declaration) but not the *address* of the actual code. The **linker** fills that hole by connecting `main.o`'s "call square" to the real machine code in `math.o`.

### Diagram for this example

```
math.h ─── (declaration only: int square(int x);)
   │  pasted into both ↓
   ├────────────────────────┐
   │                        │
   ▼                        ▼
math.cpp ──┐          main.cpp ──┐
           │                     │
   [Preprocessor]        [Preprocessor]
           │                     │
           ▼                     ▼
   ┌───────────────┐     ┌────────────────┐
   │ TU 1          │     │ TU 2           │
   │ decl + square │     │ decl + main    │
   │ definition    │     │ (calls square) │
   └───────────────┘     └────────────────┘
           │                     │
     [Compiler]            [Compiler]
           │                     │
           ▼                     ▼
        math.o                main.o
   (square's code)      (main + unresolved
           │              "call square")
           │                     │
           └──────────┬──────────┘
                      ▼
                  [Linker]
              (resolves "call square"
               in main.o → code in math.o)
                      │
                      ▼
                 executable
```

**Takeaway:** the header is copy-pasted into *both* `.cpp` files (giving both the *declaration*), but only `math.cpp` carries the *definition* — so `main.o` is left with an unresolved reference that the linker patches to `math.o`.

## Compilation Commands (g++)

### Separate compilation (the `-c` way)

```bash
# Step 1: compile each .cpp to a .o  (the -c flag = "compile only, don't link")
g++ -c math.cpp -o math.o
g++ -c main.cpp -o main.o

# Step 2: link the .o files into an executable
g++ math.o main.o -o myprogram

# Step 3: run it
./myprogram
```

The key flag is **`-c`** => "compile to object file, **stop before linking**." This is what lets each TU become its own `.o`.

### One-shot (the shortcut)

For a small project, let `g++` make the TUs, compile, and link in one go:

```bash
g++ main.cpp math.cpp -o myprogram
```

`g++` still internally creates two TUs → two (temporary) `.o` files → links them; it just cleans up the intermediates for you.

### Why the two-step `-c` way exists

| | One-shot (`g++ *.cpp`) | Separate (`-c` then link) |
| --- | --- | --- |
| Change 1 file | recompiles **everything** | recompile **only that `.o`**, then relink |
| Speed on big projects | slow | fast (this is what `make` / build systems exploit) |

### Common pitfall

```bash
g++ main.cpp -o myprogram      # linker error: undefined reference to `square`
```

Compiling `main.cpp` **alone** fails at the **link** stage — `main.o` has the unresolved `square` hole and there is no `math.o` to fill it. You must hand the linker *both* objects.
