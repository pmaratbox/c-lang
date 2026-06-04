# 0211 — Command (Undo)

Execute an AddCommand that takes a counter from 0 to 5, then undo it back to 0, printing `5 0`. The command struct stores the target counter and amount, with execute()/undo() applying and reverting the change.

## Run

    make && ./command
