COMP = g++
OPTIONS = -c -O3 -std=c++11
OUTPUT = ./output

tsp: rdata.o brute.o main.o
	$(COMP) $(OUTPUT)/brute.o $(OUTPUT)/greedy.o $(OUTPUT)/rdata.o $(OUTPUT)/main.o -o $(OUTPUT)/tsp

main.o: main.cpp
	$(COMP) $(OPTIONS) main.cpp -o $(OUTPUT)/main.o

rdata.o: ./rdata/rdata.cpp
	$(COMP) $(OPTIONS) ./rdata/rdata.cpp -o $(OUTPUT)/rdata.o

brute.o: ./brute-force/brute.cpp
	$(COMP) $(OPTIONS) ./brute-force/brute.cpp -o $(OUTPUT)/brute.o

greedy.o: ./greedy-algorithm/greedy.cpp
	$(COMP) $(OPTIONS) ./greedy-algorithm/greedy.cpp -o $(OUTPUT)/greedy.o

clean:
	rm $(OUTPUT)/*.o $(OUTPUT)/tsp
