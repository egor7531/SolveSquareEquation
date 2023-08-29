//square.cpp-программа, котора€€ решает квадратное ур-е <3

#include <stdio.h>
#include <cmath>
#include <cassert>

#include "ProgramTesting.h"
#include "InOutPut.h"
#include "SolutionOfEquation.h"


int main(){

    Hello();

    const int sizeCoeffs = 3;
    double coeffs[sizeCoeffs] = {};

    inputCoeffsAndCheck(coeffs, sizeCoeffs);

    const int sizeRoots=2;
    double roots[sizeRoots];

    Number_of_decisions nRoots=solveSquare(coeffs,roots);

    printRoots(roots,nRoots);

    return 0;
}









