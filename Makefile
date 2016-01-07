CC = clang++ -std=c++11

all:
	$(CC) -g thunderclap.cpp main.cpp

test:

clean:
	rm -r ./a.out
