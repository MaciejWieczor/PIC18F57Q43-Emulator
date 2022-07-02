main: main.o asemblator.o
	gcc -o main main.o asemblator.o -lm

asemblator.o: asemblator.c 
	gcc -c asemblator.c

main.o: main.c
	gcc -c main.c

clean:
	rm program program.o asemblator.o
