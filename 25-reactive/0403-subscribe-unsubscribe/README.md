# 0403 — Subscribe and Unsubscribe

Return a Subscription from subscribe() and use it to unsubscribe so later values are not delivered. In C the subscription is a small struct with a `closed` flag the source checks before each push.

## Run

    make -s && ./subscribeunsubscribe
