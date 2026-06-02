# 0038 — String Methods

Split `"a,b,c"` on commas, upper-case each part, and join them with `-`, printing `A-B-C`. C strings are mutable `char` arrays. `strtok` walks the tokens (mutating the buffer with NUL terminators), `toupper` upper-cases each character, and `strcat` concatenates with `-` separators — with manual length management throughout.

## Run

    make && ./strmethods
