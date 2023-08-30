//! @file SquareSolutionMain.cpp
//!
//! @author Kokonin Egor
//! @date  Data: 2023-08-29
//! @mainpage
//!
//! SquareSolutionMain.cpp - это файл, которая реализует решение квадратного уравнения по заданным коэф-там a, b, c.


#include <stdio.h>
#include <cmath>
#include <cassert>
#include <TXlib.h>
#include <string.h>

#include "ProgramTesting.h"
#include "InOutPut.h"
#include "SolutionOfEquation.h"


int main(int argc, char * argv[])
{
    if(argc>1 && !strcmp(argv[1],"-test"))
        testAll();

    const int coeffSize = 3;
    double coeffs[coeffSize] = {};

    inputCoeffsAndCheck(coeffs, coeffSize);

    const int rootSize = 2;
    double roots[rootSize] = {};

    Number_Roots nRoots = solveSquare(coeffs, roots);

    printRoots(roots, nRoots);

    return 0;
}
