CFLAGS ?= -Wall -Wextra -std=c11

modules: main.c mathutil.c mathutil.h
	$(CC) $(CFLAGS) -o modules main.c mathutil.c

clean:
	rm -f modules

.PHONY: clean
