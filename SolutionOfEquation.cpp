#include <stdio.h>
#include <cassert>
#include <cmath>

#include "SolutionOfEquation.h"
#include "ZeroComparison.h"


double dis(double a,double b,double c){
    return b*b-4*a*c;
}

Number_of_decisions solveLinear(double b,double c,double * x){

    assert(x != NULL);

    if(zeroComparison(b)==0)

        return zeroComparison(c)==0 ? INF_ROOTS : NO_ROOTS;

    else{

        if(zeroComparison(c)==0)

            *x=0;

        else

            *x=-c/b;

        return ONE_ROOTS;
    }
}


 Number_of_decisions solveSquare(double coeffs[],double roots[]){

    if(zeroComparison(coeffs[0])==0)

        return solveLinear(coeffs[1],coeffs[2],&roots[0]);

    else{

        if(zeroComparison(coeffs[1])==0){

            if(zeroComparison(coeffs[2])==0){

                roots[0]=roots[1]=0;

                return ONE_ROOTS;
            }

            else if(zeroComparison(coeffs[0]*coeffs[2])<0){

                roots[0]=sqrt(-coeffs[2]/coeffs[0]);
                roots[1]=-roots[0];

                return TWO_ROOTS;
            }
            else

                return NO_ROOTS;
        }

        else{

            if(zeroComparison(coeffs[2])==0){

                roots[0]=0;
                roots[1]=-coeffs[1]/coeffs[0];

                return TWO_ROOTS;

            }
            else{

                double D=dis(coeffs[0],coeffs[1],coeffs[2]);

                if(zeroComparison(D)==0){

                    roots[0]=roots[1]=-coeffs[1]/(2*coeffs[0]);

                    return ONE_ROOTS;
                }
                else if(zeroComparison(D)>0){

                    double sqrt_D=sqrt(D);

                    roots[0]=(-coeffs[1]+sqrt_D)/(2*coeffs[0]);
                    roots[1]=(-coeffs[1]-sqrt_D)/(2*coeffs[0]);

                    return TWO_ROOTS;
                }
                else

                    return NO_ROOTS;
            }
        }
    }
}
