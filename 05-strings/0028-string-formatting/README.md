# 0028 — String Formatting

Format the float `3.14159` to two decimals and zero-pad the integer `42` to width five, printing `pi: 3.14` and `id: 00042`. `printf` conversion specifiers do the work: `%.2f` fixes two decimals and `%05d` zero-pads to width 5. The decimal point follows `LC_NUMERIC`, which defaults to the locale-independent "C" locale unless `setlocale` changes it.

## Run

    make && ./formatting
