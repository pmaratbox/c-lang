CFLAGS ?= -Wall -Wextra -std=c11

consumer: main.c
	$(CC) $(CFLAGS) -pthread -o consumer main.c

clean:
	rm -f consumer

.PHONY: clean
