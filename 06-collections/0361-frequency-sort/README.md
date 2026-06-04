# 0361 — Frequency Sort

Sort [1,1,2,3,3,3] by descending frequency (ties keep first-seen order), printing `3 3 3 1 1 2`. In C counts are tallied in first-seen order, then a stable insertion sort orders the groups by count.

## Run

    make && ./frequencysort
