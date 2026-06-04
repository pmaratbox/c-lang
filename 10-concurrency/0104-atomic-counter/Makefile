CFLAGS ?= -Wall -Wextra -std=c11

counter: main.c
	$(CC) $(CFLAGS) -pthread -o counter main.c

clean:
	rm -f counter

.PHONY: clean
