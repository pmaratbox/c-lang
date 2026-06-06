# 0415 — SwitchMap

Implement switchMap: when a new outer value arrives, cancel the previous inner subscription before starting the new one. In C we keep the previous inner's two scheduler tokens and mark them dead before scheduling the new inner's events.

## Run

    make -s && ./switchmap
