# 0260 — Pack and Unpack Bits

Pack r=1,g=2,b=3 into one integer (8 bits each) then unpack them, printing `1 2 3`. Shifts combine the channels and `& 0xff` extracts each one back.

## Run

    make && ./packunpackbits
