# 0164 — Merge Maps

Merge {a:1,b:2} and {b:3,c:4} with the right map winning on conflicts, printing `a:1 b:3 c:4`. With no built-in map, entries are kept in an array and overwritten on a key match, then sorted by key.

## Run

    make && ./merge
