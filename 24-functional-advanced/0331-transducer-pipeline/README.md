# 0331 — Transducer Pipeline

Compose map(+1) with filter(even) and run it over [1,2,3,4], printing `2 4`. Each transducer step is a function that transforms its value then forwards to the next step, fusing map and filter into one pass.

## Run

    make && ./transducerpipeline
