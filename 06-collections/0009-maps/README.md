# 0009 — Maps

Build an associative array, look up `"two"`, and print its value and the number
of entries. C has no built-in map type — the common approach is an array of
key/value structs searched linearly with `strcmp` (a real program with many
keys would use a hash table, often from a third-party library).

## Run

    make && ./maps
