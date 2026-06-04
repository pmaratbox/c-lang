# 0283 — Rabin-Karp Search

Use rolling-hash Rabin-Karp to find all start indices of "ab" in "xabxab", printing `1 4`. A modular polynomial hash rolls across the text and `strncmp` confirms each candidate.

## Run

    make && ./rabinkarp
