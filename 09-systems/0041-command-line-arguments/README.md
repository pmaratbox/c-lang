# 0041 — Command-line Arguments

Read the first command-line argument and greet it, so running with `Ada` prints `hello, Ada`. `main(int argc, char *argv[])` receives the count and the vector; `argv[0]` is the program name and `argv[1]` the first argument. `argc` guards against reading past the end.

## Run

    make && ./args Ada
