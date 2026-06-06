# 0404 — Cold vs Hot Observable

Contrast a cold observable (re-runs its producer per subscriber) with a hot one (shares a single execution, so late subscribers miss earlier values). In C the observers are plain callbacks pushing into fixed `Sink` arrays, with no heap allocation.

## Run

    make -s && ./coldvshotobservable
