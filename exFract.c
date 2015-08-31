
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "exFract.h"
#include <unistd.h>
#include <getopt.h>
#include "mandelbrot.h"

int main(int argc, char *argv[])
{
    //Initalizes default value of the resolution and parameters
    int resolution = 1000;
    int maxIterations = 80;
    double xLow = -2.0;
    double yLow = -2.0;
    double xHigh = 2.0;
    double yHigh = 2.0;
    double xRange, yRange;
    
    if (argc > 2) {
        parseInputs(argc, argv, &resolution, &maxIterations);
    }
    
    //Checks the distance of the calculation to enable zooming
    xRange = -xLow + xHigh;
    yRange = -yLow + yHigh;
    
    mandelbrot(resolution,maxIterations,xRange,yRange,yLow,xLow);
    
    return EXIT_SUCCESS;
    
}

// Parsing the command line arguments using getopt: http://www.gnu.org/software/libc/manual/html_node/Getopt.html
void parseInputs(int argc, char* argv[], int *resolution, int *maxIterations){
    int opt;
    while ((opt = getopt(argc, argv, "r:i:")) != -1)
        switch (opt) {
            case 'r':
                *resolution = atoi(optarg);
                break;
            
            case 'i':
                *maxIterations = atoi(optarg);
                break;
            default:
                fprintf (stderr,
                         "Invalid or uncomplete flags \n");
                exit(EXIT_FAILURE);
        }
}




