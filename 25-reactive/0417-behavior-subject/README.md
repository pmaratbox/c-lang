# 0417 — BehaviorSubject

Implement a BehaviorSubject that holds a current value and replays it immediately to each new subscriber. In C the subject is a struct holding the current value plus a fixed array of observer callbacks, and subscribe invokes the callback once before registering it.

## Run

    make -s && ./behaviorsubject
