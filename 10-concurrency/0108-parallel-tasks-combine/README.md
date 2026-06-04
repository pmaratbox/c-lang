# 0108 — Parallel Tasks Combined

Run two independent tasks that produce 10 and 20 concurrently, then combine (sum) their results into `30`. C has no async/await, so two pthreads run concurrently and their results are joined and summed.

## Run

    make && ./taskscombine
