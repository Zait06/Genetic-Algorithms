run: limpiar Individual Population Selection Crossover Mutation gnuplot test
test:
	g++ test.cpp Individual.o Population.o Selection.o Crossover.o Mutation.o gnuplot.o -o test

gnuplot:
	g++ ../gnuplot/gnuplot.cpp -c

Mutation:
	g++ ../Mutation/Mutation.cpp -c

Crossover:
	g++ ../Crossover/Crossover.cpp -c

Selection:
	g++ ../Selection/Selection.cpp -c

Population:
	g++ ../Population/Population.cpp -c

Individual:
	g++ ../Individual/Individual.cpp -c

limpiar:
	rm -f *.o
	rm -f *.csv
	rm -f test