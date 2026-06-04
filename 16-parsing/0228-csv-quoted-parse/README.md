# 0228 — Parse Quoted CSV

Parse the CSV row `a,"b,c",d`, respecting the quoted comma, into three fields joined by pipes `a|b,c|d`. In C we toggle an `in_quotes` flag while walking the string and emit a `|` only for unquoted commas.

## Run

    make && ./csvquotedparse
