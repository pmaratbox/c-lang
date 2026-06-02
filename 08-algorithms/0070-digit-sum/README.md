# 0070 — Digit Sum

Sum the decimal digits of `1234` (repeatedly take the last digit with `% 10` and drop it with `/ 10`) and print the total: `10`. Integer `/` truncates toward zero, so `n /= 10` drops the last digit each step.

## Run

    make && ./digitsum
