#include <stdio.h>
#include <cassert>
#include <cmath>

#include "SolutionOfEquation.h"
#include "Utility.h"


Number_of_decisions solveLinear(const double b, const double c, double * x)
{

    assert(x != NULL);

    if(zeroComparison(b) ==0 )

        return zeroComparison(c)==0 ? INF_ROOTS : NO_ROOTS;



    if(zeroComparison(c)==0)

        *x=0;

    else

        *x=-c/b;

    return ONE_ROOTS;
}


 Number_of_decisions solveSquare(const double coeffs[], double roots[])
 {

    assert(coeffs != NULL);
    assert(roots  != NULL);

    const double a = coeffs[0];
    const double b = coeffs[1];
    const double c = coeffs[2];

    double *x1 = &roots[0];
    double *x2 = &roots[1];

    if(zeroComparison(a) == 0)

        return solveLinear(b, c, x1);



    if(zeroComparison(b) == 0)
    {

        if(zeroComparison(c) == 0)
        {

            *x1 = *x2 = 0;

            return ONE_ROOTS;
        }

        if(zeroComparison(a*c) < 0)
        {

            *x1 = sqrt(-c/a);
            *x2 = -(*x1);

            return TWO_ROOTS;
        }

            return NO_ROOTS;

    }


    if(zeroComparison(c) == 0)
    {

        *x1 = 0;
        *x2 = -b/a;

        return TWO_ROOTS;

    }


    double D = b*b-4*a*c;

    if(zeroComparison(D) == 0)
    {

        *x1 = *x2 = -b/(2*a);

        return ONE_ROOTS;
    }

    if(zeroComparison(D) > 0)
    {

        double sqrt_D=sqrt(D);

        *x1=(-b+sqrt_D)/(2*a);
        *x2=(-b-sqrt_D)/(2*a);

        return TWO_ROOTS;
    }

        return NO_ROOTS;

}
