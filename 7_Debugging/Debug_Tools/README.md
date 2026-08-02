# Debug & Binary Inspection Tools

A collection of notes and demo programs covering debugging, memory-error
detection, and binary inspection tools on Linux.

## Debugging Tools

| Tool | Purpose | Reference File |
|------|---------|----------------|
| **gdb** | Interactive source-level debugger — breakpoints, stepping, inspecting variables/memory. Compile with `-g`; run with `gdb ./a.out --tui`. | [`debugger/95_gdb_tutorial.c`](debugger/95_gdb_tutorial.c), [`debugger/gdb_debugger.c`](debugger/gdb_debugger.c) |
| **valgrind** | Detects memory leaks, buffer overflows, and invalid reads/writes at runtime. Run with `valgrind ./a.out`. | [`3_tool_valgrind.c`](3_tool_valgrind.c), [`96_valgrind_gdb_tutorial.c`](96_valgrind_gdb_tutorial.c) |
| **AddressSanitizer (ASan)** | Compiler-instrumented detection of buffer overflows, use-after-free, and leaks. Compile with `gcc -fsanitize=address`. | [`6_tool_address_sanitizer.c`](6_tool_address_sanitizer.c), [`7_tool_address_sanitizer_2.c`](7_tool_address_sanitizer_2.c) |
| **assert** | Built-in runtime sanity checks for invariants; can be stripped from release builds. `#include <assert.h>`. | [`4_tool_assertions.c`](4_tool_assertions.c) |
| **strace** | Traces system calls a process makes to the OS. Run with `strace ./a.out`. | [`5_tool_traces.c`](5_tool_traces.c) |
| **ltrace** | Traces library calls (e.g. into `libc`) a process makes. Run with `ltrace ./a.out`. | [`5_tool_traces.c`](5_tool_traces.c) |

## Binary Inspection Tools

All located under [`binary_inspection/`](binary_inspection/).

| Tool | Purpose |
|------|---------|
| **Hex editor** (GHex, Bless, Hex Fiend, HexEd.in) | View/edit the raw bytes of a file in hexadecimal. |
| **xxd** | Command-line hex dump of a file. |
| **hexdump** | Command-line hex dump (`hexdump -C file`). |
| **strings** | Extracts all printable strings from a binary (`strings ./a.out`). |
| **readelf** | Inspects ELF structure — headers, symbols, sections, segments (`readelf -h/--symbols/--segments`). |
| **objdump** | Dumps symbol table, section contents, and disassembly (`objdump -t/-s/-d`). |
| **nm** | Lists symbols from an object file or binary. |
| **strip** | Removes symbols and debug info from a binary (`strip ./a.out`). |
| **stat** | Shows file metadata (size, permissions, timestamps). |
| **wc** | Counts bytes/lines/words of a file. |

### Demo Programs & Notes

- [`binary_inspection/1_tool_hex_editor.c`](binary_inspection/1_tool_hex_editor.c) — hex editor intro & options
- [`binary_inspection/2_tool_gnu_binutils.c`](binary_inspection/2_tool_gnu_binutils.c) — GNU binutils walkthrough (strings, readelf, objdump, strip)
- [`binary_inspection/ELF.cpp`](binary_inspection/ELF.cpp) — ELF format demo

## Notes / Markdown References

- [`binary_inspection/binary_inspection_tools.md`](binary_inspection/binary_inspection_tools.md) — detailed notes on inspecting compiled binaries
- [`binary_inspection/ELF.md`](binary_inspection/ELF.md) — the Executable and Linkable Format explained
- [`debug_symbols.md`](debug_symbols.md) — what debug symbols are and what `-g` adds
