OPTIONS = -c -O3 -std=c++11
COMP = g++

tsp: rdata.o main.o
	$(COMP) rdata.o main.o -o tsp

rdata.o: rdata.cpp rdata.h
	$(COMP) $(OPTIONS) rdata.cpp rdata.h

main.o: main.cpp
	$(COMP) $(OPTIONS) main.cpp

clean:
	rm *.o tsp
