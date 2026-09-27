# Author: Yash Deshpande
# Date  : 26-09-2026
# Tutor : Jacob Sorber (How to Load Libraries at Runtime)
# Link  : https://youtu.be/_kIa4D7kQ8I?si=EwArkKk7tnzrdaWM

CC=clang
CFLAGS=-Wall -g
BINS=libplus1.so libplus2.so test.elf

all: $(BINS)

%.so: %.c
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^

%.elf: %.c
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	rm $(BINS)
	rm -r *.so