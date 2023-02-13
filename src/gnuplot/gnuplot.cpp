#include "gnuplot.h"
#include <stdio.h>

gnuplot::gnuplot(){
    gnuplotpipe = popen("gnuplot -persitent", "w");
    if (!gnuplotpipe)
        cerr<<("gnuplot not found!");
}

gnuplot::~gnuplot(){
    fprintf(gnuplotpipe, "exit\n");
    pclose(gnuplotpipe);
}

void gnuplot::operator<<(const string & command){
    fprintf(gnuplotpipe,"%s\n", command.c_str());
    fflush(gnuplotpipe);
    fflush(gnuplotpipe);
}