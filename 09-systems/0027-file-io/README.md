# 0027 — File I/O

Write `hello, file` to a file, read it back, delete the file, and print `read: hello, file`. `fopen` returns a `FILE *` stream; `fputs` writes, `fread` fills a buffer (its return is the byte count, used to NUL-terminate), and `fclose` flushes and closes the stream. `remove` deletes the path. Production code checks `fopen` for `NULL`.

## Run

    make && ./fileio
