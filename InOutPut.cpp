#include <stdio.h>

#include "InOutPut.h"

void clearBuffer(void){

    while(getchar()!='\n'){
        continue;
    }

}

void inputCoeffsAndCheck(double coeffs[],const int sizeCoeffs){

    int nvalue=0;

    printf("Enter a,b,c: ");

    for(int i=0;i<sizeCoeffs;i++)
        nvalue+=scanf("%lf",&coeffs[i]);

    while(nvalue!=3){

        nvalue=0;

        clearBuffer();

        printf("Error: values a,b,c aren't numbers\n");

        printf("Enter a,b,c: ");

        for(int i=0;i<sizeCoeffs;i++)
            nvalue+=scanf("%lf",&coeffs[i]);

    }

}

void printRoots(double roots[],Number_of_decisions nRoots){

    switch (nRoots){
        case NO_ROOTS: printf("No Roots\n");
                break;
        case ONE_ROOTS: printf("x=%.2lf\n",roots[0]);
                break;
        case TWO_ROOTS: printf("x1=%.2lf, x2=%.2lf\n",roots[0],roots[1]);
                break;
        case INF_ROOTS: printf("Any number\n");
                break;
        default: printf("ERROR NUMBER OF ROOTS");
                break;
    }
}

