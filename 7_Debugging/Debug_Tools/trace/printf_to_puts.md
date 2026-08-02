# Why does `ltrace` show `puts` instead of `printf`?

You call `printf("Hello World\n")` in the source, but `ltrace` reports a call to `puts`.

## The compiler rewrote your `printf` into `puts`

This is a well-known **optimization done by GCC/Clang** (even at `-O0`). When the compiler sees a `printf` call that:

1. Has **no format specifiers** (no `%d`, `%s`, etc.), and
2. Ends its string with a **single newline `\n`**,

...it replaces it with `puts`, because `puts` is simpler and faster — it just writes a string plus a newline, with no format-parsing overhead.

The transformation:

```c
printf("Hello World\n");   // what you wrote
puts("Hello World");       // what the compiler emitted
```

Note how the `\n` disappeared from the argument — that's because **`puts` automatically appends a newline**. So the behavior is identical, but the actual library call is `puts`. That's what `ltrace` faithfully reports: it traces the *real* library calls in the binary, not your source code.

## Reading the output

```
puts("Hello World"Hello World      <- "Hello World" is the arg; the program's actual output interleaves
)                            = 12   <- return value 12 = 11 chars + 1 newline
+++ exited (status 0) +++
```

The `= 12` is `puts`'s return value: it returns the number of characters written (`"Hello World"` = 11 + the appended `\n` = 12). The messy interleaving is just your program's stdout ("Hello World") printing in the middle of ltrace's line.

## Proving it to yourself

Turn off the optimization and you'll see `printf`:

```bash
gcc -fno-builtin 5_tool_traces.c -o a.out
ltrace ./a.out
```

`-fno-builtin` tells the compiler not to substitute its known "builtin" versions of standard functions, so your literal `printf` survives.

You can also see it at the assembly level:

```bash
gcc -S 5_tool_traces.c -o -    # look for a `call puts` instead of `call printf`
```

## Takeaway

`ltrace` shows what the binary **actually does**, which can differ from your source code. The compiler is free to rewrite calls as long as the observable behavior is unchanged. The same idea applies to inlining — a traced function might vanish entirely because it got inlined into its caller.
