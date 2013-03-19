CC=g++
CFLAGS=-g

all: main.cpp
	$(CC) $(CFLAGS) main.cpp -o asm_pass
clean:
	rm asm_pass *~
