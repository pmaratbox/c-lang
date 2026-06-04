# 0366 — Sparse Matrix

Store only nonzero entries; with (1,1)=5 set, read (1,1) (5) and (0,0) (0), printing `5 0`. In C a small array of (row,col,val) cells acts as the coordinate map, and a missing key reads as 0.

## Run

    make && ./sparsematrix
