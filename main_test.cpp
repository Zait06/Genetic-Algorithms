#include <iostream>
// #include "Individual/Individual.h"
#include "gnuplot/gnuplot.h"

int main(){

    srand(time(NULL));

    gnuplot myPlot;

    myPlot << "plot [-pi/2:pi] cos(x),-(sin(x) > sin(x+1) ? sin(x) : sin(x+1))";
    // char* operation;

    // sprintf(operation, "%s\n%s\n%s", "", "", "");

    // Individual<bool> ind(6);
    // ind.initRandom();
    // ind.print();

    // Individual<float> ind1(6);
    // ind1.initRandom(10);
    // ind1.print();

    // Individual<int> ind2(6);
    // ind2.initRandom(10);
    // ind2.print();

    return 0;

}