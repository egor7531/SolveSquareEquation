#include <stdio.h>

#include "Utility.h"

int zeroComparison(double x)
{
    const double DELTA=0.00001;

    if (x < -DELTA)
        return -1;

    if(x>DELTA)
        return 1;

    return 0;
}

void clearBuffer()
{

    while(getchar()!='\n')
        continue;

}
