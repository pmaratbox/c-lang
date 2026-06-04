CFLAGS ?= -Wall -Wextra -std=c11

compareandswap: main.c
	$(CC) $(CFLAGS) -pthread -o compareandswap main.c

clean:
	rm -f compareandswap

.PHONY: clean
