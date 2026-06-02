# 0031 — Type Conversion & Parsing

Parse the string `"42"` into an integer and `"3.5"` into a float, then convert the integer back to a string, printing `int: 42`, `float: 3.5`, and `str: 42`. `atoi`/`atof` are the simplest converters but report no errors (returning 0 on failure); `strtol`/`strtod` do, via an end pointer. `snprintf` formats a number back into a character buffer.

## Run

    make && ./conversion
