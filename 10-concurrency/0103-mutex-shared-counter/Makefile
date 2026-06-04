CFLAGS ?= -Wall -Wextra -std=c11

sharedcounter: main.c
	$(CC) $(CFLAGS) -pthread -o sharedcounter main.c

clean:
	rm -f sharedcounter

.PHONY: clean
