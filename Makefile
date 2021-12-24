OBJS = Individual.o main.o
BINARY = main

all = project

project: $(OBJS)
	g++ build/*.o -o build/$(BINARY)

main.o: main_test.cpp
	g++ main_test.cpp -c -o build/main.o

Individual.o: Individual/Individual.cpp Individual/Individual.h
	g++ Individual/Individual.cpp -c -o build/Individual.o

clean:
	rm -f build/$(BINARY) build/*.o
