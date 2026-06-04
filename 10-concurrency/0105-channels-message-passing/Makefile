CFLAGS ?= -Wall -Wextra -std=c11

messagepassing: main.c
	$(CC) $(CFLAGS) -pthread -o messagepassing main.c

clean:
	rm -f messagepassing

.PHONY: clean
