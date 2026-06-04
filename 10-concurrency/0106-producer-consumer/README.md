# 0106 — Producer / Consumer

A producer sends 1..5 to a consumer that sums them, printing `15`. In C a bounded ring buffer with two condition variables blocks when full or empty.

## Run

    make && ./consumer
