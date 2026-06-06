# 0423 — EventEmitter (Pub/Sub)

Build a multi-topic EventEmitter with on(topic, handler), emit(topic, payload), and off(topic, handler). In C the handlers are plain function pointers stored in a small fixed array, and off() simply flips a subscription's active flag.

## Run

    make -s && ./eventemitterpubsub
