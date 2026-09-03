
# Debug Tools — Notes

- **Author:** Yash Deshpande
- **Date:** 01-08-2026
- **LLM Model:** Claude (Opus 4.8)

## Sources

- [How to Inspect Compiled Binaries (binutils, objdump)](https://youtu.be/bWMIpHVRFUo?si=qwOCRNm_hl9A1acK) — YouTube video by Jack Sorber
- [Tame binary headaches with a Hex Editor](https://youtu.be/-eDY7yh-CyA?si=8Ge66MWHDfMxzTnZ) — YouTube video by Jack Sorber

## Index

1. [Exhaustive Tools List](#exhaustive-tools-list)
2. [What is a hex editor?](#what-is-a-hex-editor)
3. [What `xxd` does](#what-xxd-does)
4. [Interpreting the hex dump](#interpreting-the-hex-dump)
5. [Strings tool](#strings-tool)
6. [Symbol table](#symbol-table)
7. [`objdump -t` vs `readelf --symbols`](#objdump--t-vs-readelf---symbols)
8. [Sections — `objdump -s`](#sections--objdump--s)
9. [Where read-only data lives in the address space](#where-read-only-data-lives-in-the-address-space)
10. [Disassembly — `objdump -d`](#disassembly--objdump--d)
11. [Segments (program headers) — `readelf --segments`](#segments-program-headers--readelf---segments)
12. [File offsets vs virtual addresses](#file-offsets-vs-virtual-addresses)
13. [`strip` — remove symbols and debug info](#strip--remove-symbols-and-debug-info)
14. [`objdump` vs `readelf` — which tool, when](#objdump-vs-readelf--which-tool-when)


# How to inspect Compiled Binaries

## Exhaustive Tools List
- xxd 
- hexdump
- readelf
- strings
- strip
- objdump
- stat
- wc
- nm
- ldd


## What is a hex editor?

A **hex editor** is a tool that lets you view and edit the raw bytes of a file displayed in hexadecimal (base-16). Instead of interpreting a file as text or a specific format, it shows every byte as its hex value (`00`–`FF`), usually alongside an ASCII rendering:

```
Offset    00 01 02 03 04 05 06 07  08 09 0A 0B 0C 0D 0E 0F   ASCII
00000000  7F 45 4C 46 02 01 01 00  00 00 00 00 00 00 00 00   .ELF............
```

### Why they're useful

- **Inspecting binary file formats** — ELF headers, magic numbers, executables (exactly what these notes do).
- **Reverse engineering** — reading how a compiled program is laid out when you don't have the source.
- **Patching bytes directly** — fixing corrupted files, or changing a value in a binary without recompiling (the password-patch trick below).
- **Understanding data layout** — seeing how numbers, strings, and structs are actually stored on disk / in memory.

### Quick start with `xxd`

`xxd` comes bundled with Vim, so it's already installed on most systems.

```bash
xxd a.out | less             # view the hex dump, page through it
xxd a.out > hex_dump.txt     # dump to a file for study

# round-trip editing: dump -> edit the text -> rebuild the binary
xxd a.out > dump.txt         # 1. dump to text
#   ...edit the hex values in dump.txt...
xxd -r dump.txt > a.out      # 2. reverse (-r) back into a binary
```

The `-r` (reverse) flag is what turns `xxd` from a *viewer* into an *editor*: edit the hex in the text dump, then reverse it back into bytes. For interactive editing there are dedicated TUIs (`hexedit`, `bvi`) and GUIs (`ghex`), but `xxd` + a text editor covers most needs.

## What `xxd` does

`xxd` is a dumb, faithful byte printer: it reads the file byte by byte, prints each as a two-digit hex value, and renders the ASCII column. It does **not** parse, validate, or care what the file *is* — a binary, text file, image, or corrupted garbage all get dumped identically. A text file only *looks* readable in the ASCII column because its bytes happen to be printable characters.

### File size from the dump

The offset column is just a running byte counter, so the file size is:

**file size = last offset + number of bytes on the last line**

The last offset alone gives the size rounded down to the nearest 16; you add the bytes on the final line. A partial last line (shorter hex/ASCII columns) adds fewer than 16. Example from `a.out`:

```
last offset:        0x4430
bytes on last line:  + 8      (only "0000 0000 0000 0000")
                    ────────
total size:         0x4438  = 17464 bytes
```

Shortcuts that avoid the math:

```bash
xxd a.out | tail -1     # eyeball the last offset + trailing bytes
stat -c '%s' a.out      # exact size directly
wc -c < a.out           # exact size (counts bytes)
```

compile with debug symbols: gcc -g 2_tool_gnu_binutils.c

Then get the hex dump in the of its executable hex_dump.txt: xxd a.out > hex_dump.txt


## Interpreting the hex dump

Each line of an `xxd` dump has three columns:

```
00000000: 7f45 4c46 0201 0100 0000 0000 0000 0000  .ELF............
└──┬───┘  └──────────────┬──────────────────────┘  └──────┬──────┘
 offset          hex bytes (16 per line)               ASCII view
```

1. **Offset (leftmost):** byte position in the file, in hex. `00000010` = byte 16, `00000020` = byte 32. Each line covers 16 bytes.
2. **Hex bytes (middle):** the raw file contents. `xxd` groups them in pairs (2 bytes per group, 8 groups = 16 bytes). Each pair like `7f` is one byte (0–255).
3. **ASCII (right):** each byte shown as a character if printable, otherwise a `.`. Handy for spotting text embedded in a binary.

### Reading the ELF header

A Linux executable is an **ELF** file, and its header (the first bytes) is self-describing:

| Bytes                | Meaning                                                        |
|----------------------|---------------------------------------------------------------|
| `7f 45 4c 46`        | Magic number — `45 4c 46` is ASCII `E L F` (see `.ELF` on right). Identifies the file type. |
| `02`                 | 64-bit (`01` would be 32-bit)                                  |
| `01`                 | Little-endian byte order                                       |
| `01`                 | ELF version                                                    |
| `03 00` (offset 0x10)| Type = `ET_DYN` (a PIE executable)                            |
| `3e 00` (offset 0x12)| Machine = `0x3e` = x86-64                                      |

### Gotcha: little-endian

x86 machines store multi-byte numbers **backwards**. At offset `0x12` you see `3e 00`, but the actual value is `0x003e`, not `0x3e00`. Always reverse the byte order when reading numbers wider than one byte.

### Decode it automatically

`xxd` shows raw bytes; to have the ELF structure parsed into labels for you:

```bash
readelf -h a.out      # parses the header fields (x86-64, DYN, ...)
```

The `readelf` output maps directly onto the same bytes you can decode by hand in the dump.

### `xxd` vs `readelf -h` — same bytes, different lens

`readelf -h` reads the *same first 64 bytes* that sit at the top of your `xxd` dump — it just labels them. The `readelf` **Magic** line literally *is* the first 16 bytes of the dump:

```
readelf:   Magic:  7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00
hex_dump:  00000000: 7f45 4c46 0201 0100 0000 0000 0000 0000
```

Full mapping of header fields to their location in the dump:

| readelf field            | Value    | Offset | Bytes in dump          |
|--------------------------|----------|--------|------------------------|
| Class                    | ELF64    | 0x04   | `02`                   |
| Data                     | little endian | 0x05 | `01`                |
| Version                  | 1        | 0x06   | `01`                   |
| OS/ABI                   | System V | 0x07   | `00`                   |
| Type                     | DYN      | 0x10   | `0300` → `0x0003`      |
| Machine                  | X86-64   | 0x12   | `3e00` → `0x003e`      |
| Entry point              | 0x1080   | 0x18   | `8010 0000...` → `0x1080` |
| Start of program headers | 64       | 0x20   | `4000...` → `0x40`     |
| Start of section headers | 15096    | 0x28   | `f83a 0000...` → `0x3af8` |
| Size of this header      | 64       | 0x34   | `4000` → `0x40`        |
| Size of program headers  | 56       | 0x36   | `3800` → `0x38`        |
| Number of program headers| 13       | 0x38   | `0d00` → `0x0d`        |

Every multi-byte value needs the little-endian reversal (`f83a` → `0x3af8` = 15096); `readelf` does that math for you.

**The key difference:**

- **`xxd`** is format-agnostic. It dumps raw bytes with no idea what the file is — it would dump a JPEG, a `.txt`, or garbage identically.
- **`readelf`** understands the ELF spec. It knows byte 0x12 is "Machine", knows to reverse endianness, and translates `0x3e` → "X86-64".

So `readelf -h` = the header bytes from `xxd`, parsed and cleaned. Nothing new is read from the file.

One nuance: `readelf -h` shows *only* the 64-byte header. The full `xxd` dump also contains everything after it — machine code, string tables, section data — which other `readelf`/`objdump` flags parse.


Jack sorber in his video opens a hexeditor, for the executable -> then changes the password in the hex file & without recompilation, the file starts accepting this new password instead of the old one. 
so basically modified the bytes of the compiled binary & hacked the executable without requiring recompilation


GNU Binutils

## Strings tool

`strings` scans any binary — executable or otherwise — and pulls out all the printable strings it contains, making it the quickest way to grab readable text out of a binary file.

`strings a.out` scans the binary and prints every run of **printable characters** (default: 4+ in a row, terminated by a non-printable byte). It looks at the same raw bytes as `xxd`, but filters *out* the machine code and keeps only the human-readable islands buried in it.

Capture the output: `strings a.out > string_tool.txt`

### The security angle

`strings` exposes hardcoded string literals — including secrets. In the sample program the output contained:

```
FEEDBEEF        ← a hardcoded comparison value / "password" in the code
Correct         ← success message
Incorrect       ← failure message
myValue         ← a variable name (leaked by -g debug symbols)
```

This is the same idea as the hex-editor trick above: combined with the `strcmp` symbol, `strings` reveals exactly what the program checks against — no source code needed. Finding a hardcoded secret is often a one-liner:

```bash
strings a.out | grep -iE 'password|correct|feed|secret'
```

### What the other strings reveal about the build

| Strings                                   | What they reveal                                              |
|-------------------------------------------|--------------------------------------------------------------|
| `/lib64/ld-linux-x86-64.so.2`             | The dynamic linker — confirms a dynamically-linked 64-bit ELF |
| `puts`, `strcmp`, `__libc_start_main`     | Library functions the program calls (symbol/relocation tables) |
| `libc.so.6`, `GLIBC_2.2.5`, `GLIBC_2.34`  | Shared library dependency + required glibc versions          |
| `GCC: (Ubuntu 13.3.0...)`                 | The exact compiler version used                              |
| `GNU C17 ... -g -fstack-protector-strong` | The full compile flags (note `-g` is on)                    |
| `2_tool_gnu_binutils.c`, `/home/.../`, `string.h` | Source file path and includes — leaked by debug info |
| `main`, `argv`, `argc`, `myValue`         | Symbol names — variables and functions (thanks to `-g`)     |

### Why this binary leaks so much

The output is unusually rich because it was compiled with **`-g`** (debug symbols), which embeds source paths, variable names, and types into the binary. A release build stripped with `strip a.out` removes most of this — the variable names, source paths, and debug symbols vanish, leaving mainly library names and literals.


## Symbol table

A **symbol table** is a directory the compiler/linker builds that maps **names in your code** (functions, variables) to their **addresses and properties** in the binary. It's how the linker, debuggers, and `nm` answer "where does `main` live?" or "what is `myValue`?" without guessing — an index with one row per named thing saying *what it is, where it is, how big, and who can see it*.

Dump it: `readelf --symbols a.out > symbols.txt`

### Reading the columns

```
Num:    Value          Size Type    Bind   Vis      Ndx Name
 33: 0000000000001169   104 FUNC    GLOBAL DEFAULT   16 main
 19: 0000000000004010     4 OBJECT  GLOBAL DEFAULT   25 myValue
```

| Column    | Meaning                                                              |
|-----------|---------------------------------------------------------------------|
| **Value** | The address (offset) where the symbol lives in memory               |
| **Size**  | How many bytes it occupies                                          |
| **Type**  | `FUNC` (function), `OBJECT` (variable/data), `FILE` (source file), `NOTYPE` (marker) |
| **Bind**  | Visibility scope: `LOCAL`, `GLOBAL`, or `WEAK`                      |
| **Ndx**   | Which section it's in (`UND` = undefined, defined elsewhere)         |
| **Name**  | The symbol name                                                     |

From the sample: `main` is a `FUNC` of size 104 bytes at `0x1169`; `myValue` is a 4-byte `OBJECT` (an `int`). This is exactly what a debugger like `gdb` uses to let you `break main` or `print myValue`.

### `UND` (undefined) symbols

```
22: ... FUNC GLOBAL DEFAULT UND puts@GLIBC_2.2.5
26: ... FUNC GLOBAL DEFAULT UND strcmp@GLIBC_2.2.5
```

`UND` means "this program **uses** this function but doesn't define it — find it elsewhere at runtime." These are the libc functions the code calls (`strcmp` shows up again because of the string/password comparison).

### `.symtab` vs `.dynsym`

The file has **two** symbol tables:

- **`.dynsym`** — the *dynamic* symbol table. Only symbols needed at **runtime** for dynamic linking (like `puts`, `strcmp`). Always present, even in stripped binaries.
- **`.symtab`** — the *full* table, including local symbols like `main`, `myValue`, `deregister_tm_clones`.

This ties back to stripping: **`strip` deletes `.symtab`**, so a release build hides your function/variable names but still runs, because `.dynsym` stays for the linker.

### Related tool

```bash
nm a.out           # a more compact view of the same symbol table
nm -D a.out        # just the dynamic symbols (.dynsym)
```

## `objdump -t` vs `readelf --symbols`

Both read the **same underlying ELF symbol table(s)** — for everyday use they're interchangeable. The difference is formatting and toolchain philosophy. Same `main` entry in each:

```
readelf:  33: 0000000000001169  104 FUNC  GLOBAL DEFAULT 16 main
objdump:  0000000000001169 g     F .text  0000000000000068              main
```

Same address (`0x1169`), same size (104 = `0x68`), same "global function". Just arranged differently.

### Formatting differences

| Aspect          | `readelf --symbols`                          | `objdump -t`                        |
|-----------------|----------------------------------------------|-------------------------------------|
| Section column  | Numeric index (`Ndx 16`)                     | Section **name** (`.text`, `.data`) |
| Flags           | Spelled out (`FUNC GLOBAL DEFAULT`)          | Compact chars (`g F`, `l O`, `w`)   |
| Size            | Decimal (`104`)                              | Hex (`0x68`)                        |
| Both tables     | Prints `.dynsym` *and* `.symtab`, labeled    | Merges into one `SYMBOL TABLE:`     |

### Decoding objdump's flag columns

`objdump` packs several fields into single characters:

```
0000000000004010 g     O .data  0000000000000004  myValue
                 │     │  │
                 │     │  └─ section the symbol lives in
                 │     └──── O = OBJECT (data), F = FUNC, df = file
                 └────────── binding: g=GLOBAL, l=LOCAL, w=WEAK
```

So `l F .text` = local function in `.text`; `F *UND*` = an undefined function (like `puts`). `*UND*` and `*ABS*` are objdump's names for the special sections `readelf` shows as `UND`/`ABS`.

### The real difference

- **`readelf`** is a pure ELF parser — it *only* understands ELF and reads the format directly. Strict and canonical.
- **`objdump`** is built on the BFD library (same backend as the linker) and supports **many** formats (ELF, PE, Mach-O, COFF...). Its real strength is elsewhere: it can **disassemble** machine code, which `readelf` cannot.

```bash
objdump -d a.out      # disassemble to assembly — the killer feature
objdump -s a.out      # full section contents as hex
```

For *just symbols*, pick whichever output reads easier (`objdump -t` shows section names, often nicer). Reach for `objdump` specifically when you want disassembly.


## Sections — `objdump -s`

`objdump -s a.out` dumps the **full raw contents of every section** as a hex+ASCII view — like `xxd`, but *grouped and labeled by section* instead of one flat blob. This is the payoff of everything above: an ELF file isn't one undifferentiated lump of bytes, it's divided into named **sections**, each holding a specific *kind* of data.

Capture it: `objdump -s a.out | tee objdump_sections.txt`

### What a section is

The compiler/linker partitions the binary by purpose. The important ones:

| Section              | What it holds                                                    |
|----------------------|-----------------------------------------------------------------|
| `.text`              | The actual **machine code** (your compiled functions)           |
| `.rodata`            | **Read-only data** — string literals, constants                 |
| `.data`              | Initialized global/static variables (like `myValue`)            |
| `.bss`               | Uninitialized globals (takes no file space, just a size)        |
| `.dynsym` / `.dynstr`| Dynamic symbol table + its string names                         |
| `.plt` / `.got`      | Jump tables for calling shared-library functions at runtime     |
| `.debug_*`           | DWARF debug info (present because of `-g`)                       |
| `.comment`           | The compiler version string                                     |

### `.rodata` is the smoking gun

```
.rodata:
 2000 01000200 46454544 42454546 00436f72  ....FEEDBEEF.Cor
 2010 72656374 00496e63 6f727265 637400    rect.Incorrect.
```

`FEEDBEEF`, `Correct`, `Incorrect` sit in `.rodata` starting at address `0x2000`, readable three ways that all agree:

- **hex:** `46454544 42454546`
- **ASCII column:** `FEEDBEEF`
- by hand: `0x46`=`F`, `0x45`=`E`, `0x45`=`E`, `0x44`=`D`...

The `00` bytes between strings are the **null terminators** (`\0`) ending each C string. This is exactly what `strings` picked out earlier — but now you see *where* those strings live and their exact addresses.

### How this connects the whole toolchain

Each tool is a different view of the same sections:

- `xxd` → all bytes, no structure
- `strings` → just the printable runs (mostly from `.rodata`, `.comment`, `.dynstr`)
- `readelf --symbols` → the `.symtab`/`.dynsym` sections parsed
- `objdump -s` → **every section's raw contents, labeled**
- `objdump -d` → disassembles just `.text` into assembly

### Security tie-in

`objdump -s` shows the hardcoded `FEEDBEEF` *and its address* (the `0x2000` region). Combined with the hex-editor trick above, this is how you'd locate the exact byte offset to patch to change the password — you now know it's in `.rodata` and can compute its file offset.

### Related

```bash
readelf -x .rodata a.out   # hex-dump one specific section
readelf -S a.out           # list all sections with sizes/addresses (no contents)
```


## Where read-only data lives in the address space

String literals and other read-only data live in **`.rodata`**, which the loader maps into a **read-only (`R`) LOAD segment** — sandwiched between the code and the writable data.

```
HIGH addresses
   ┌──────────────────────┐
   │  stack               │  grows DOWN (locals, params)
   │        v             │
   ├──────────────────────┤
   │        ^             │
   │  heap                │  grows UP (malloc/new)
   ├──────────────────────┤
   │  .bss    @ 0x4014    │  RW  — uninitialized globals
   │  .data   @ 0x4000    │  RW  — initialized globals
   ├──────────────────────┤
   │  .rodata @ 0x2000    │  R   <- string literals & const data
   ├──────────────────────┤
   │  .text   @ 0x1080    │  R E — machine code
   └──────────────────────┘
LOW addresses
```

`.rodata` lands in the LOAD segment whose flags are `R` only — **not writable, not executable**. That's hardware-enforced by the MMU, not just a convention.

### What goes in `.rodata`

- **String literals** — `"FEEDBEEF"`, `"Correct"`, `"Incorrect"` (at `0x2004`, `0x200d`, `0x2015`)
- **`const` globals** — `const int limit = 100;`
- **`const` arrays / lookup tables** — `const char *names[] = {...}`
- **Compiler-generated tables** — jump tables for large `switch` statements
- **Floating-point constants** — literals like `3.14159` that can't be encoded as an immediate

### The practical consequence — a classic C bug

This is *why* it matters that `.rodata` is read-only:

```c
char *p = "hello";     // p points INTO .rodata
p[0] = 'H';            // <- SIGSEGV! writing to a read-only page

char arr[] = "hello";  // COPY made on the stack (or .data if global)
arr[0] = 'H';          // <- fine, it's writable memory
```

Both look similar in source, but `char *p = "..."` gives a pointer into `.rodata`, while `char arr[] = "..."` copies the bytes into writable storage. The segfault is the MMU enforcing the `R`-only segment permission. This is also why modern C++ requires `const char *` for string literals — the type system warning you before the hardware does.

### Two more things worth knowing

- **Literals are deduplicated.** If `"hello"` appears in five places, the compiler typically stores it **once** in `.rodata` and points all five references at the same address (the `M`/`S` "merge/strings" section flags in `readelf -S`).
- **`.rodata` is loaded from the file, unlike `.bss`.** Its bytes physically exist on disk — which is why `strings` and `objdump -s` can show `FEEDBEEF` at file offset `0x2004`. Contrast `.bss`, which has no file bytes at all (`NOBITS`) and is zero-filled at load time.

### Tie-back to the patching trick

Since `.rodata` is read-only *at runtime*, the running program can't change `FEEDBEEF` itself. But the **file on disk isn't protected** — which is why the hex-editor patch works. You modify the bytes before the loader ever maps them, and the process starts up with the new value already in its read-only page.


## Disassembly — `objdump -d`

`objdump -d a.out` **disassembles**: it translates the raw machine-code bytes in `.text` back into human-readable **assembly instructions**. This is the one thing `readelf` can't do. Every tool above showed *data*; this shows the *logic* — the actual CPU instructions the C code compiled into.

Capture it: `objdump -d a.out | tee objdump_disassembly.txt`

### The three columns

```
1194:  48 8d 15 69 0e 00 00   lea  0xe69(%rip),%rdx
└─┬─┘  └───────┬─────────┘    └──────┬─────────┘
address    raw machine-code       assembly (what the
(offset)   bytes (opcode)          CPU actually does)
```

- **Left:** where the instruction lives (matches symbol-table addresses — `main` at `0x1169`).
- **Middle:** the exact bytes you'd also see in `xxd`.
- **Right:** the decoded instruction. `objdump -d` is the bridge between raw bytes and meaning.

### Reading the sample `main` — the password check

The whole program logic is visible:

```asm
117c:  cmpl  $0x1,-0x4(%rbp)      ; compare argc with 1
1180:  jg    1189                 ; if argc > 1, jump ahead (an arg was given)
1182:  mov   $0xffffffff,%eax     ; else return -1
1187:  jmp   11cf                 ; ...and exit

1189:  mov   -0x10(%rbp),%rax     ; load argv
118d:  add   $0x8,%rax            ; argv + 8  ->  argv[1]  (pointers are 8 bytes)
1191:  mov   (%rax),%rax          ; dereference -> the string you typed
1194:  lea   0xe69(%rip),%rdx     ; load address 0x2004 -> "FEEDBEEF"
11a1:  call  strcmp@plt           ; strcmp(your_input, "FEEDBEEF")
11a6:  test  %eax,%eax            ; did strcmp return 0 (equal)?
11a8:  jne   11bb                 ; not equal -> jump to "Incorrect"
11b4:  call  puts@plt             ; equal -> print (0x200d = "Correct")
11c5:  call  puts@plt             ; the "Incorrect" branch (0x2015)
```

### This ties the whole investigation together

At `0x1194`, `lea 0xe69(%rip),%rdx` (objdump comments it as `# 2004`) loads the **exact `.rodata` address** where `FEEDBEEF` lives — the string found with `objdump -s`. The disassembly shows the instruction that loads it right before the `strcmp` call. The full password check across all tools:

- `strings` → *that* `FEEDBEEF` exists
- `objdump -s` → it lives at `.rodata` address `0x2004`
- `objdump -d` → `main` loads `0x2004` and passes it to `strcmp` at `0x11a1` (the check itself)

### The hack, fully explained

The hex-editor trick from the notes maps precisely onto this:

- **Patch the data:** change the `FEEDBEEF` bytes in `.rodata` (found via `-s`) → program accepts a different password.
- **Patch the logic:** change the `jne` at `0x11a8` to `je` (or a `nop`) → program accepts *any* password, because the comparison branch is inverted/removed. That one-byte edit (`75` → `74`) is the classic crack.

### Variants

```bash
objdump -d a.out                    # AT&T syntax (default, shown above)
objdump -d -M intel a.out           # Intel syntax (mov rdx, ... — often clearer)
objdump --disassemble=main a.out    # just one function
```


## Segments (program headers) — `readelf --segments`

**Segments** are the runtime view of the binary — instructions to the OS **loader** on how to map the file into memory when the program runs. They're the counterpart to sections:

- **Sections** (`.text`, `.rodata`, `.data`...) = the **build / link-time view**. Fine-grained, for the *linker* and *debuggers*.
- **Segments** (aka *program headers*) = the **run-time / load view**. Coarse-grained, for the *OS loader*.

The same bytes are described **both ways**. The `Section to Segment mapping` at the bottom of the output shows how many sections get bundled into each segment.

Capture it: `readelf --segments a.out | tee readelf_segments.txt`  (`readelf -l` is the same thing.)

### The key type: `LOAD`

Only `LOAD` segments actually get copied into memory at launch; everything else is metadata *about* loading. Their **Flags** (permissions) tell the story:

| Segment        | Flags | Meaning              | Sections it holds                          |
|----------------|-------|----------------------|--------------------------------------------|
| LOAD @ `0x0000`| `R`   | Read-only            | ELF header, `.dynsym`, `.dynstr`, `.interp`|
| LOAD @ `0x1000`| `R E` | Read + **Execute**   | `.text`, `.plt`, `.init` — **the code**    |
| LOAD @ `0x2000`| `R`   | Read-only            | `.rodata` — the `FEEDBEEF` string          |
| LOAD @ `0x2db0`| `RW`  | Read + **Write**     | `.data`, `.bss` — writable variables       |

### Why the grouping matters — memory protection

The loader groups sections by **permission** because the CPU/MMU enforces protection per memory page:

- **Code** (`R E`): executable but **not writable** → attackers can't overwrite instructions.
- **Constants** (`R`): read-only, not executable → `FEEDBEEF` can't be modified at runtime or run as code.
- **Variables** (`RW`): writable but **not executable** → injected data can't run (**W^X / NX bit**).

That's the deep reason sections exist separately: so they can be *sorted into segments by permission* and the OS can enforce security boundaries.

### Two size columns explain `.bss`

```
FileSiz 0x264   MemSiz 0x268    <- MemSiz is bigger
```

- **FileSiz** = bytes stored in the file on disk.
- **MemSiz** = bytes it occupies in memory.

When MemSiz > FileSiz, the extra bytes are `.bss` — uninitialized globals. They take *no file space* (no point storing zeros); the loader zero-fills that gap in memory.

### Other segments worth knowing

- **`INTERP`** → names the dynamic linker (`/lib64/ld-linux-x86-64.so.2`), which loads shared libraries. Same string `strings` found.
- **`GNU_STACK`** with `RW` (not `RWE`) → marks the stack **non-executable** (NX). If it said `RWE`, the binary would be vulnerable to classic stack shellcode.
- **`GNU_RELRO`** → "RELocation Read-Only": hardening that makes certain sections read-only *after* the linker finishes, blocking GOT-overwrite attacks.

### Sections vs segments side by side

```bash
readelf -S a.out          # SECTIONS  — build/link view (fine-grained)
readelf --segments a.out  # SEGMENTS  — load/runtime view (coarse, by permission)
readelf -l a.out          # same as --segments (-l = program headers)
```

### Many sections → one segment

Multiple sections collapse into a single segment, **grouped by permission**:

```
Segment 03 (LOAD, R E):   .init .plt .plt.got .plt.sec .text .fini
Segment 05 (LOAD, RW):    .init_array .fini_array .dynamic .got .data .bss
```

**Why bundle:** the *linker* wants fine-grained sections (it cares that `.text` is code, `.plt` is a jump table, `.init` is startup). The *loader* doesn't — it only asks "what permissions?" per memory chunk. All of `.init`/`.plt`/`.text`/`.fini` are code → all need `R E` → so the loader lumps them into one segment and maps them in a single operation.

**Why it works:** the linker deliberately lays sections out in address order so same-permission sections are **contiguous**. One segment then covers the whole range (e.g. `VirtAddr 0x1000` + `MemSiz 0x1e1`). Each `LOAD` must be page-aligned to `0x1000` (4 KB), so scattering sections randomly would waste memory.

**It's not strictly one-way, though:**

- **One section can appear in *multiple* segments.** `.dynamic` is in segment 05 (`LOAD` — map into memory), segment 06 (`DYNAMIC` — "here's the dynamic-linking info"), *and* segment 12 (`GNU_RELRO` — "make read-only after startup"). Same bytes, three descriptions for three purposes.
- **Some sections map to *no* segment.** `.symtab`, `.debug_*`, `.comment` aren't in any `LOAD` segment — not needed at runtime, so never loaded into memory. They exist on disk only for tools like `gdb`, which is why `strip` can remove them without breaking execution.

```
SECTIONS (linker's view)          SEGMENTS (loader's view)
.init  ┐
.plt   │
.text  ├──────►  one R E LOAD segment  (map as executable)
.fini  ┘

.data  ┐
.bss   ├──────►  one RW  LOAD segment  (map as writable)
.got   ┘

.debug_info ───► (no segment — never loaded, disk-only)
```

Sections are for building, segments are for running; the many-to-one bundling is how the OS turns dozens of link-time sections into a handful of permission-protected memory regions.


## File offsets vs virtual addresses

Not every address these tools print is a virtual address. There are **three** distinct kinds of number, and mixing them up will break a patching attempt.

### 1. File offsets — position of bytes *on disk*

- `xxd` / `hexdump` offset column
- `readelf -S` **Offset** column
- `readelf -l` **Offset** column
- `readelf -h`: "Start of section headers: 15096 (bytes **into file**)"

### 2. Virtual addresses — where bytes land *in memory*

- `readelf -S` **Address** column
- `readelf -l` **VirtAddr** column
- Symbol table **Value** (`main` @ `0x1169`, `myValue` @ `0x4010`)
- `objdump -d` instruction addresses
- Entry point (`0x1080`)

### They are genuinely different numbers

```
[25] .data    Address 0x4000    Offset 0x3000      <- differ by 0x1000
LOAD          VirtAddr 0x3db0   Offset 0x2db0      <- differ by 0x1000
```

The linker shifts them so each segment starts on a fresh 4 KB page in memory. `.rodata` happens to have Address == Offset (`0x2000` both) — a **coincidence** of this layout, not a rule.

**Practical consequence for patching:** to hex-edit `FEEDBEEF` you need the **file offset**, not the virtual address. They match for `.rodata` here, but to patch something in `.data`, `objdump -d` says `0x4010` while the byte to edit sits at file offset `0x3010`.

```
file_offset = virtual_address - (segment VirtAddr - segment Offset)
```

### 3. Sections with no virtual address at all

```
[27] .comment    Address 0x0000000000000000    Offset 0x3014
```

`.comment`, `.symtab`, `.debug_*`, `.strtab` show Address `0x0` because **they're never loaded into memory** — they exist only in the file. Address `0` means "not applicable," not "address zero." Same reason they belong to no `LOAD` segment.

### Even the virtual addresses aren't the final runtime ones

This binary is **Type: DYN (PIE)**, so every address shown is a **link-time address relative to a load base of 0**. At runtime **ASLR** picks a random base and slides everything:

```
actual runtime address = random_base + 0x1169
```

Attach `gdb` to the running process and `main` sits at something like `0x5555_5555_5169`, not `0x1169`. Static tools can't know the base — it's chosen fresh each run. For a non-PIE binary (`Type: EXEC`, built with `-no-pie`) the addresses *are* the literal runtime addresses, no sliding.

### Summary

| Tool / column                     | What the number is                        |
|-----------------------------------|-------------------------------------------|
| `xxd`, `hexdump` offset           | **File offset**                           |
| `readelf -S` Offset               | **File offset**                           |
| `readelf -l` Offset               | **File offset**                           |
| `readelf -S` Address              | Virtual (link-time, base 0 for PIE)       |
| `readelf -l` VirtAddr             | Virtual (link-time)                       |
| `nm` / `readelf --symbols` Value  | Virtual (link-time)                       |
| `objdump -d` addresses            | Virtual (link-time)                       |
| `.comment` / `.symtab` Address = 0| No virtual address — never loaded         |
| gdb on a *running* process        | **Real** runtime address (base + offset)  |

Static inspection tools show either file offsets or link-time virtual addresses. Only a debugger on a live process shows true runtime virtual addresses.


## `strip` — remove symbols and debug info

`strip a.out` deletes the symbol table and debug info from the binary — the naming/metadata a debugger uses, but which the CPU doesn't need to *run* the program. It's the counterpart to all the inspection above: `strip` removes most of what made those investigations easy.

### What it changed

The sample binary went from **17,464 → 14,480 bytes** (~17% smaller):

| Before `strip`                              | After `strip`                          |
|---------------------------------------------|----------------------------------------|
| `.symtab` present (38 entries: `main`...)   | **`.symtab` gone**                     |
| `.debug_*` sections (from `-g`)             | **`.debug_*` gone**                    |
| `nm a.out` listed symbols                   | `nm: a.out: no symbols`                |
| `readelf --symbols` → 52 lines              | 11 lines (only `.dynsym` left)         |

### What survives, and why

`.dynsym` (`puts`, `strcmp`, `__libc_start_main`) **can't be stripped** — they're the dynamic symbols the runtime linker *needs* to connect the program to `libc.so.6` at launch. This is the `.symtab` vs `.dynsym` distinction in action:

- `.symtab` (local names: `main`, `myValue`) → only used by debuggers → **stripped**.
- `.dynsym` (library links: `puts`, `strcmp`) → required at runtime → **kept**.

### Effect on the other tools

- `readelf --symbols` / `nm` → `main`, `myValue` **gone**; can't `break main` cleanly in gdb.
- `objdump -d` → **still works**, but functions show as raw addresses (`0x1169`) instead of `<main>`. Code intact, only labels vanished.
- `strings` → **`FEEDBEEF`, `Correct`, `Incorrect` still there.** `strip` does *not* touch `.rodata`.

### Key takeaways

1. **Stripping ≠ security.** It removes convenience labels, not logic or data. The password `FEEDBEEF` is still readable via `strings`, and the `strcmp` check is still in `objdump -d`. Stripping makes reversing slightly more tedious, not impossible.
2. **It's a release-build norm** — production binaries are stripped to save space and hide internal names, which is why real-world reversing means reading disassembly with no function names.
3. **Irreversible on this file** — once stripped, `main`/`myValue` are gone; recompile to get them back. Keep an unstripped copy for debugging.

### Variants

```bash
strip a.out                 # remove all symbols + debug (what was run)
strip --strip-debug a.out   # remove ONLY debug info, keep .symtab
strip -s a.out              # explicit "strip all"
gcc -g ...  then  strip     # common: build with symbols, ship stripped
```


## `objdump` vs `readelf` — which tool, when

**One-sentence difference:**

- **`readelf`** is a pure **ELF parser** — it *only* understands ELF and reports its structures verbatim. Strict, canonical, no interpretation beyond decoding the spec. Doesn't use BFD, so it shows the raw truth even for malformed binaries.
- **`objdump`** is a **BFD-based Swiss army knife** — built on the same backend library as the linker (`libbfd`), it understands *many* formats (ELF, PE/Windows, Mach-O/macOS, COFF...) and can **disassemble** machine code, which `readelf` cannot.

### Where they overlap (either works)

Same underlying data, different formatting:

| Task                       | `readelf`           | `objdump`             |
|----------------------------|---------------------|-----------------------|
| ELF header                 | `readelf -h`        | `objdump -f` (partial)|
| Section headers            | `readelf -S`        | `objdump -h`          |
| Symbol table               | `readelf --symbols` | `objdump -t`          |
| Segments / program headers | `readelf -l`        | *(no equivalent)*     |
| Dump a section's bytes     | `readelf -x .rodata`| `objdump -s -j .rodata`|

### Where each is unique

**Only `objdump` can:**

```bash
objdump -d a.out        # DISASSEMBLE machine code -> assembly  (the killer feature)
objdump -S a.out        # disassembly interleaved with source (needs -g)
objdump -M intel -d     # Intel-syntax disassembly
```

**Only `readelf` (cleanly) can:**

```bash
readelf -l a.out        # program headers / LOAD segments (loader's view)
readelf -d a.out        # .dynamic section (shared-lib deps, RPATH)
readelf -n a.out        # notes (build-id, ABI tag)
readelf --version-info  # symbol versioning (GLIBC_2.34 etc.)
```

### Which to reach for

| You want to...                              | Use                       |
|---------------------------------------------|---------------------------|
| See the assembly / reverse-engineer logic   | **`objdump -d`**          |
| Understand runtime memory layout & perms    | **`readelf -l`**          |
| Check what shared libraries a binary needs  | **`readelf -d`** (or `ldd`)|
| List/inspect symbols quickly                | either (`nm` is lighter)  |
| Debug a *malformed* / suspicious ELF        | **`readelf`** (raw truth) |
| Work with non-ELF binaries (PE, Mach-O)     | **`objdump`**             |
| Dump raw section bytes                       | either                    |

**Rule of thumb:** `readelf` to understand the ELF *structure*; `objdump` to read the *code*. Both ship as part of GNU **binutils**, alongside `nm`, `strings`, `strip`, `ar`, `ld`, and `size`.
