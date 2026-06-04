# 0176 — Graph DFS

Depth-first traverse from node 0 of the graph 0:[1,2] 1:[0,3] 2:[0,3] 3:[1,2], printing visit order `0 1 3 2`. A recursive helper that marks `visited` and recurses into each unvisited neighbor in list order gives a natural depth-first search.

## Run

    make && ./dfs
