main: main.cpp asemblator.c parser.cpp procesor.cpp
	g++ -o main main.cpp asemblator.c parser.cpp procesor.cpp

clean:
	rm main main.o program.o asemblator.o procesor.o
