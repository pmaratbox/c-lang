# 0416 — Subject Multicast

Implement a Subject that multicasts each emission to all current observers; two observers both receive 1 then 2. The Subject holds a small fixed array of observers and a `next` that loops over them in subscription order.

## Run

    make -s && ./subjectmulticast
