#include "Population.h"
#include "Selection.h"
#include "Crossover.h"
#include "Mutation.h"
#include "gnuplot.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    Population p00 = Population(100);
    Selection s00 = Selection();
    Crossover c00 = Crossover();
    Mutation m00 = Mutation(0.1);
    gnuplot plt;

    FILE *fmax = fopen("max.tmp","w");
    FILE *fmin = fopen("min.tmp","w");
 
    p00.initPop(8,1);   // eight bits random

    fprintf(fmax,"%d %f\n",0,p00.getMax());
    fprintf(fmin,"%d %f\n",0,p00.getMin());

    for(int i = 0; i < 50; i++){
        Population p02 = c00.onePoint(s00.roulette(p00));
        m00.mutBin(&p02);
        p00 = p02.join(p00);
        fprintf(fmax,"%d %f\n",i+1,p00.getMax());
        fprintf(fmin,"%d %f\n",i+1,p00.getMin());
    }
    
    plt("set title \"Genetic Algorithm\"");
    plt("plot 'max.tmp' with linespoints ls 4 lt rgb \"red\", 'min.tmp' with linespoints ls 4 lt rgb \"blue\"");

    fclose(fmax);
    fclose(fmin);

    return 0;
}