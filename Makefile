# Compiler and test file names are volatile
all: first second

first:
	gcc compiler.c

second: first
	./a.out test.c

clean:
	rm -f a.out