# 0324 — Either Monad

Chain Either computations: a successful divide chain yields 2, and a divide-by-zero yields an error, printing `2 err`. A tagged struct carrying either a value or an error tag, with a `bind` that short-circuits on Left, models Either in C.

## Run

    make && ./eithermonad
