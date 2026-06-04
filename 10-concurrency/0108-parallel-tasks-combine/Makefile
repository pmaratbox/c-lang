CFLAGS ?= -Wall -Wextra -std=c11

taskscombine: main.c
	$(CC) $(CFLAGS) -pthread -o taskscombine main.c

clean:
	rm -f taskscombine

.PHONY: clean
