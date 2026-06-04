# 0125 — Temp File Roundtrip

Write a string to a temporary file, read it back, confirm it matches, delete the file, and print `roundtrip: ok`. C writes with `fputs`, reads with `fread`, compares via `strcmp`, then `remove`s the file.

## Run

    make && ./fileroundtrip
