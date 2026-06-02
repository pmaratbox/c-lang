# 0032 — Math Functions

Take the square root of `16`, raise `2` to the 10th power, the absolute value of `-5`, and the larger of `3` and `9`, printing `sqrt: 4`, `pow: 1024`, `abs: 5`, and `max: 9`. `sqrt` and `pow` come from `<math.h>` and return `double` (cast to `int`); `abs` is the integer version from `<stdlib.h>`. C has no built-in `max`, so a ternary `a > b ? a : b` stands in.

## Run

    make && ./math
