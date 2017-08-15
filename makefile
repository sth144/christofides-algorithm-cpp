cc=g++
cflags=-c -std=c++11

all: driver

driver: main.cpp tsp.cpp tsp.h
	g++ main.cpp tsp.cpp -o tsp
	
clean:
	rm -f a.out
	rm -f *.o
	rm -f driver
