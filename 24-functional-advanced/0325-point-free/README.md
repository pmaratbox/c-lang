# 0325 — Point-Free Style

Express "sum of squares" point-free (compose map-square with sum) and apply it to [1,2,3], printing `14`. C has no first-class composition, so a fused `sum . map square` is written as one higher-order fold over a function pointer.

## Run

    make && ./pointfree
