# 0418 — ReplaySubject

Implement a ReplaySubject with a buffer of the last 2 values, replayed to a late subscriber, which then also receives new values. In C the subject is a plain struct holding a small fixed array and a single observer with a `next` function pointer.

## Run

    make -s && ./replaysubject
