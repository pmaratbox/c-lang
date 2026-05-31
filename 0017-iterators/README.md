# 0017 — Iterators

Take the numbers 1 through 5, keep the even ones, double each, and add them up — a filter, then a map, then a reduce — printing the final sum. C has no iterators or higher-order collection functions, so the whole pipeline collapses into a single counted `for` loop: the filter is the `if`, the map is the `* 2`, and the reduce is the `sum` accumulator. The array length is recovered with the usual `sizeof(nums) / sizeof(nums[0])`.

## Run

    make && ./iterators
