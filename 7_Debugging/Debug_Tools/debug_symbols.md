# Debug Symbols — Notes

- **Author:** Yash Deshpande
- **Date:** 01-08-2026
- **LLM Model:** Claude (Opus 4.8)

> Companion to [`binary_inspection_tools.md`](binary_inspection_tools.md) and [`ELF.md`](ELF.md).

## What are debug symbols?

**Debug symbols** are extra metadata the compiler embeds in a binary that maps the *machine code back to your source code* — variable names, function names, types, and crucially the line-number ↔ address mapping. They're what let a debugger say "you crashed at `main.c:42` in variable `myValue`" instead of "you crashed at address `0x1169`."

## What `-g` adds

The `gcc -g` (or `g++ -g`) flag is what generates debug symbols. Concretely, it adds these to the binary:

| What                | Where it shows up when inspecting                             |
|---------------------|--------------------------------------------------------------|
| Source file path    | `strings` shows `/home/.../2_tool_gnu_binutils.c`            |
| Variable/type names | `myValue`, `long long int`, `unsigned char` in `strings`     |
| The `.debug_*` sections | `readelf -S` lists `.debug_info`, `.debug_line`, `.debug_str`... |
| Compile flags       | `GNU C17 ... -g ...` embedded in `.comment`                  |

Those `.debug_*` sections **are** the debug symbols. They're stored in **DWARF** format (the standard debug-info format on Linux/ELF).

## Two different things called "symbols"

A subtle but important distinction:

- **The symbol table (`.symtab`)** — names + addresses of functions/variables (`main` @ `0x1169`, `myValue` @ `0x4010`). Present even *without* `-g` (though minimal). The "who lives where" index.
- **Debug symbols (`.debug_*`, DWARF)** — the *rich* data `-g` adds: line numbers, local variables, struct layouts, scopes, the source-to-assembly mapping. Much bigger and more detailed.

People loosely call both "debug symbols," but `-g` specifically adds the second, heavyweight kind on top.

## Why they matter — the payoff

With debug symbols, `gdb` can:

```bash
break main.c:42        # break at a source line (not a hex address)
print myValue          # inspect a variable by its name
backtrace              # show the call stack with function names + line numbers
```

Without them, you're stuck at the raw level of `objdump -d` — addresses and register names, no source context:

```bash
objdump -S a.out    # -S interleaves SOURCE with assembly — only works because of -g
```

## The cost, and the connection to `strip`

Debug symbols make binaries **bigger** and **leak information** (source paths, internal names). That's why:

- Production binaries are compiled with `-g` for internal builds, then **`strip`ped** for release. `strip` removes `.symtab` *and* the `.debug_*` sections (in the sample binary: 17,464 → 14,480 bytes). See the `strip` section in [`binary_inspection_tools.md`](binary_inspection_tools.md).
- Modern practice is to `strip` the shipped binary but save the debug symbols separately, so a crash can be debugged later without shipping symbols to users:

```bash
objcopy --only-keep-debug a.out a.out.debug   # extract symbols to a side file
strip a.out                                   # ship the small stripped binary
# later: point gdb at a.out.debug to symbolize a crash
```

## In one line

Debug symbols (the `.debug_*` / DWARF data added by `-g`) are the compiler's translation table from machine code back to your source — line numbers, variable names, and types — enabling source-level debugging, at the cost of size and information disclosure.
