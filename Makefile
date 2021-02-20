run: limpiar Individual Population Selection Crossover Mutation gnuplot test
test:
	g++ test.cpp Individual.o Population.o Selection.o Crossover.o Mutation.o gnuplot.o -o test

gnuplot:
	g++ gnuplot.cpp -c

Mutation: Mutation.cpp Mutation.h
	g++ Mutation.cpp -c

Crossover: Crossover.cpp Crossover.h
	g++ Crossover.cpp -c

Selection: Selection.cpp Selection.h
	g++ Selection.cpp -c

Population: Population.cpp Population.h
	g++ Population.cpp -c

Individual: Individual.cpp Individual.h
	g++ Individual.cpp -c

limpiar:
	rm -f *.o
	rm -f *.csv
	rm -f test