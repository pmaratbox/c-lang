# 0025 — Tuples & Multiple Return

Return both the smaller and larger of `3` and `7` from one function, unpacking the pair to print `min: 3` and `max: 7`. C functions return a single value, so multiple results are returned through *out-parameters*: the caller passes `&lo` and `&hi` and the function writes through the pointers. Returning a small `struct` by value is the other common option.

## Run

    make && ./tuples
