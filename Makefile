all:main.c matrix.c matrix.h
	gcc -g main.c  matrix.c -o main
clean:
	rm -f main
