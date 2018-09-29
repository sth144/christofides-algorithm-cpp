
inp	?= gpx

all: tsp

tsp: main.cpp tsp.cpp tsp.h
	g++ -std=c++11 -Wall -O2 main.cpp tsp.cpp -o $@
	
clean:
	rm -f a.out
	rm -f *.o
	rm -f tsp

test: tsp
	./tsp $(inp)
	gnuplot -e "plot '$(inp).tour' using 2:3 with lines" -

