#ifndef GNUPLOT_H_
#define GNUPLOT_H_
#include <iostream>
#include <string>
using namespace std;

class gnuplot{
    public:
        gnuplot();
        ~gnuplot();
        void operator() (const string & comand);
    protected:
        FILE *gnuplotpipe;
};

#endif