CFLAGS ?= -Wall -Wextra -std=c11

barriersync: main.c
	$(CC) $(CFLAGS) -pthread -o barriersync main.c

clean:
	rm -f barriersync

.PHONY: clean
