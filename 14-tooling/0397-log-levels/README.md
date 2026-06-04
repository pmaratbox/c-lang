# 0397 — Log Level Filter

With a threshold of WARN, log messages at INFO, WARN, and ERROR but only emit WARN and ERROR, on two lines. An enum ordering levels lets a simple integer comparison gate each message.

## Run

    make && ./loglevels
