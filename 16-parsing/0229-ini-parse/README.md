# 0229 — Parse INI

Parse the INI text with section [s] and key k=v, printing the flattened entry `s.k=v`. In C we track the current section and split each line at `=` with `strchr`.

## Run

    make && ./iniparse
