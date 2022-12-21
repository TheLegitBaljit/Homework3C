all: isort txtfind

isort:isort.o
	gcc -Wall -o isort isort.o

txtfind:txtfind.o
	gcc -Wall -o txtfind txtfind.o

isort.o: isort.c
	gcc -Wall -c isort.c

txtfind.o: txtfind.c
	gcc -Wall -c txtfind.c

clean:
	rm txtfind isort *.o
