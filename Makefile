# Makefile for encryption and decryption
# Matthew Ray & Davis Carson

CC = gcc
CFLAGS = -Wall -Werror

all: encrypt decrypt

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f encrypt decrypt

run:
	./encrypt attackatdawn
	./decrypt 013333011023013311014130
