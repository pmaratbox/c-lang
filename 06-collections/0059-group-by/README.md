# 0059 — Group By

Group the words `one`, `two`, `three` by their length and print each length with its words, in ascending order of length: `3:[one,two] 5:[three]`. C has no map; with the word set fixed, the code scans each candidate length from `1` upward and gathers the matching words in order — simple, if O(n·maxlen).

## Run

    make && ./groupby
