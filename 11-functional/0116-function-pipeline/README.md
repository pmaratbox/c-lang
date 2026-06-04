# 0116 — Function Pipeline

Compose inc, double, and negate into a left-to-right pipeline and apply it to 3: ((3+1)*2) negated = `-8`. An array of unary function pointers is threaded through stage by stage by `pipe`.

## Run

    make && ./pipeline
