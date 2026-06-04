# 0121 — Parse CSV

Parse the two CSV rows `alice,30` and `bob,25` into name=value pairs and print `alice=30 bob=25`. C splits each line on the comma with `strtok` and formats the pairs with `snprintf`.

## Run

    make && ./parse
