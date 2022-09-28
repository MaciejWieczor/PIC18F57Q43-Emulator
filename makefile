main: main.cpp parser.cpp procesor.cpp modules.cpp
	g++ -o main main.cpp parser.cpp procesor.cpp modules.cpp

clean:
	rm main main.o program.o procesor.o
