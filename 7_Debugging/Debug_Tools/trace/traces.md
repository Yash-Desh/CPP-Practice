
# Traces — Notes

- **Author:** Yash Deshpande
- **Date:** 02-08-2026
- **LLM Model:** Claude (Opus 5)

## Sources

| # | Video | Author | Duration |
|---|-------|--------|----------|
| 1 | [Spying on Running Programs (strace, ltrace, system calls vs function calls)](https://youtu.be/2AmP7Pse4U0?si=gg4BTFK-XSJIYCjt) | Jacob Sorber | |
## Usage

We use the program [`5_tool_traces.c`](5_tool_traces.c) for our tutorial.

Compile:

```bash
gcc 5_tool_traces.c
```
## ltrace
`strace` usage:

```bash
strace ./a.out 2>&1 | tee strace.txt
```

This has a lot of setup system calls that are present even if you comment out the hello world printf line. 
This is due to the setup of the cstd library
So we compare it with the system calls of an assembly program that doesn't import the std library. 

### Raw syscall version

Build [`rawsyscall.S`](rawsyscall.S) with `-no-pie`:

```bash
gcc -nostdlib -no-pie rawsyscall.S
strace ./a.out 2>&1 | tee rawsyscall_strace.log
```


## ltrace
`ltrace` usage:

```bash
ltrace ./a.out 2>&1 | tee ltrace.txt
```

# What do we really use strace / ltrace for ? 