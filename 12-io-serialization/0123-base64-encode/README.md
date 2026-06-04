# 0123 — Base64 Encode

Base64-encode the bytes of "hi" to get `aGk=`. C has no stdlib encoder, so we index the 64-char table manually over each 3-byte group.

## Run

    make && ./encode
