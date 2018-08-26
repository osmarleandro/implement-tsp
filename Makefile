COMP = g++
OPTIONS = -c -O3 -std=c++11
OUTPUT = ./output

tsp: brute.o nearest.o rdata.o main.o
	$(COMP) $(OUTPUT)/brute.o $(OUTPUT)/nearest.o $(OUTPUT)/rdata.o $(OUTPUT)/main.o -o $(OUTPUT)/tsp

main.o: main.cpp
	$(COMP) $(OPTIONS) main.cpp -o $(OUTPUT)/main.o

rdata.o: ./rdata/rdata.cpp
	$(COMP) $(OPTIONS) ./rdata/rdata.cpp -o $(OUTPUT)/rdata.o

brute.o: ./brute-force/brute.cpp
	$(COMP) $(OPTIONS) ./brute-force/brute.cpp -o $(OUTPUT)/brute.o

nearest.o: ./greedy-algorithm/nearest-neighbor/nearest.cpp
	$(COMP) $(OPTIONS) ./greedy-algorithm/nearest-neighbor/nearest.cpp -o $(OUTPUT)/nearest.o

clean:
	rm $(OUTPUT)/*.o $(OUTPUT)/tsp
