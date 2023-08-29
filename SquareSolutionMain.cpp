//square.cpp-программа, котора€€ решает квадратное ур-е <3

#include <stdio.h>
#include <cmath>
#include <cassert>

#include "ProgramTesting.h"
#include "InOutPut.h"
#include "SolutionOfEquation.h"


int main()
{

    needSoftwareTesting();

    const int coeffSize = 3;
    double coeffs[coeffSize] = {};

    inputCoeffsAndCheck(coeffs, coeffSize);

    const int rootSize = 2;
    double roots[rootSize] = {};

    Number_of_decisions nRoots = solveSquare(coeffs, roots);

    printRoots(roots, nRoots);

    return 0;
}









