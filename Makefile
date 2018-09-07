COMP = g++
OPTIONS = -c -O3 -std=c++11
OUTPUT = ./output

tsp: cheaper.o bn-heuristic.o nearest.o brute.o rdata.o common.o main.o
	$(COMP) $(OUTPUT)/cheaper.o $(OUTPUT)/bn-heuristic.o $(OUTPUT)/nearest.o $(OUTPUT)/brute.o $(OUTPUT)/rdata.o $(OUTPUT)/common.o $(OUTPUT)/main.o -o $(OUTPUT)/tsp

main.o: main.cpp
	$(COMP) $(OPTIONS) main.cpp -o $(OUTPUT)/main.o

common.o: ./util/common.cpp
	$(COMP) $(OPTIONS) ./util/common.cpp -o $(OUTPUT)/common.o

rdata.o: ./rdata/rdata.cpp
	$(COMP) $(OPTIONS) ./rdata/rdata.cpp -o $(OUTPUT)/rdata.o

brute.o: ./brute-force/brute.cpp
	$(COMP) $(OPTIONS) ./brute-force/brute.cpp -o $(OUTPUT)/brute.o

nearest.o: ./greedy-algorithm/nearest-neighbor/nearest.cpp
	$(COMP) $(OPTIONS) ./greedy-algorithm/nearest-neighbor/nearest.cpp -o $(OUTPUT)/nearest.o

bn-heuristic.o: ./greedy-algorithm/bellmore-nemhauser/bn-heuristic.cpp
	$(COMP) $(OPTIONS) ./greedy-algorithm/bellmore-nemhauser/bn-heuristic.cpp -o $(OUTPUT)/bn-heuristic.o

cheaper.o: ./greedy-algorithm/cheaper-insertion/cheaper.cpp
	$(COMP) $(OPTIONS) ./greedy-algorithm/cheaper-insertion/cheaper.cpp -o $(OUTPUT)/cheaper.o

clean:
	rm $(OUTPUT)/*.o $(OUTPUT)/tsp
