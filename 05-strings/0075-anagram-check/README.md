# 0075 — Anagram Check

Check whether each pair is an anagram by comparing sorted letters — `listen`/`silent` and `hello`/`world` — printing `listen/silent: yes` and `hello/world: no`. Each word is copied and sorted with `qsort` (one-byte elements); equal sorted strings (`strcmp`) mean an anagram.

## Run

    make && ./anagram
