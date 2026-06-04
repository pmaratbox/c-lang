# 0124 — Path Manipulation

Join "/tmp" and "file.txt", then take the basename and extension, printing `/tmp/file.txt file.txt .txt`. C uses `snprintf` to join and `strrchr` to find the last slash and dot.

## Run

    make && ./manipulation
