# 0008 — Strings

Given `name = "world"`, print a greeting, the name in uppercase, and its
length. A C string is a `char *` to a null-terminated byte array. There is no
built-in uppercase for a whole string — loop and apply `toupper` to each
character. `strlen` counts the bytes up to the terminating `'\0'`.

## Run

    make && ./strings
