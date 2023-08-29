#pragma once

enum Number_of_decisions {NO_ROOTS, ONE_ROOTS, TWO_ROOTS, INF_ROOTS};

Number_of_decisions solveLinear(const double b,const double c, double * x);

Number_of_decisions solveSquare(const double coeffs[],double roots[]);
