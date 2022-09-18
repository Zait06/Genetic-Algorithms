OBJS = gnuplot.o main.o
BINARY = main

all = project

project: $(OBJS)
	g++ build/*.o -o build/$(BINARY)

main.o: main_test.cpp
	g++ main_test.cpp -c -o build/main.o

# Individual.o: Individual/Individual.cpp Individual/Individual.h
# 	g++ Individual/Individual.cpp -c -o build/Individual.o

gnuplot.o: gnuplot/gnuplot.cpp gnuplot/gnuplot.h
	g++ gnuplot/gnuplot.cpp -c -o build/gnuplot.o

clean:
	rm -f build/$(BINARY) build/*.o
