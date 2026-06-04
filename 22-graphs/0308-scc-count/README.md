# 0308 — Strongly Connected Components

Count the strongly connected components of 0->1,1->2,2->0,2->3, printing `2`. C runs Kosaraju with two DFS passes over a matrix and its transpose.

## Run

    make && ./scccount
