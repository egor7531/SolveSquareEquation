#pragma once

enum Number_of_decisions {NO_ROOTS=0,ONE_ROOTS=1,TWO_ROOTS=2,INF_ROOTS=-1};

double dis(double a,double b,double c);

Number_of_decisions solveLinear(double b,double c,double * x);

Number_of_decisions solveSquare(double coeffs[],double roots[]);
