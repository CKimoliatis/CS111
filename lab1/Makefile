OBJS = pipe.o

CFLAGS = -std=c17 -Wpedantic -Wall -O2 -pipe -fno-plt
LDFLAGS = -Wl,-O1,--sort-common,--as-needed,-z,relro,-z,now

CC = gcc

pipe: ${OBJS}
	$(CC) $(CFLAGS) -o $@ $^
	
.PHONY: clean
clean:
	rm -fd ${OBJS} pipe __pycache__/* __pycache__
