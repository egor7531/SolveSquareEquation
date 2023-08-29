#include "ZeroComparison.h"

const double DELTA=0.00001;

int zeroComparison(double x){

    if (x<-DELTA)
        return -1;
    else if(x>DELTA)
        return 1;
    else
        return 0;
}
