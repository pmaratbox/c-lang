# 0034 — Default & Named Arguments

Give a `greet` function a default greeting, then call it once without the greeting and once overriding it, printing `Hello, Ada` and `Hi, Ada`. C has no default or named arguments. A wrapper function that calls through with a fixed value (here `greet_default`) is the simplest stand-in; variadic functions or a config struct are the alternatives.

## Run

    make && ./defaults
