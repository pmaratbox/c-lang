# 0323 — Maybe Monad

Chain Maybe operations: Some(2) then +3 then *2 gives 10, and a None chain yields the fallback, printing `10 none`. A tagged struct plus a `bind` that runs the next step only when the value is present models the monad in C.

## Run

    make && ./maybemonad
