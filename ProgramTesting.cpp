#include <stdio.h>
#include <cassert>

#include "ProgramTesting.h"
#include "InOutPut.h"
#include "Utility.h"

bool checkRoots(double roots[], Number_of_decisions nRoots, double x1ref, double x2ref, Number_of_decisions nRootsRef);


void needSoftwareTesting()
{

    printf("Hello! I'm a program that solves a quadratic equation.\nDo I need to run a test to verify the program?\n");

    if(getchar() == 'y')
        testAll();

    clearBuffer();

}


void testAll()
{

    TestData allData[] = {  {0,  0,  5,  0,  0,  NO_ROOTS},
                            {0,  0,  0,  0,  0, INF_ROOTS},
                            {1,  0, -4, -2,  2, TWO_ROOTS},
                            {1, -4,  4,  2,  2, ONE_ROOTS},
                            {0, -2,  5,2.5,  0, ONE_ROOTS}  };

    int numSuccessfulTests = 0;

    int nTests = sizeof(allData)/sizeof(allData[0]);

    for(int i=0;i<nTests;i++)
        numSuccessfulTests += testOne(&allData[i], i+1);

    if(numSuccessfulTests == nTests)
        printf("All tests passed successfully\n");

}

bool checkRoots(double roots[], Number_of_decisions nRoots, double x1ref, double x2ref, Number_of_decisions nRootsRef)
{
    return ( (zeroComparison(roots[0]-x1ref)==0 && zeroComparison(roots[1]-x2ref)==0) ||
        (zeroComparison(roots[0]-x2ref)==0 && zeroComparison(roots[1]-x1ref)==0) ) &&
        nRoots==nRootsRef;
}

int testOne(const TestData * refer, int numTest)
{

    assert(refer != NULL);

    const double coeffsRef[] = {refer->a, refer->b, refer->c};

    const int RootSize = 2;
    double roots[RootSize] = {};

    Number_of_decisions nRoots = solveSquare (coeffsRef, roots);

    if(checkRoots(roots, nRoots, refer->x1, refer->x2, refer->nRootsRef))

        return 1;

    else

        printf("FAILED %d Test: x1=%lg, x2=%lg, nRoots=%d\nexpected: x1Ref=%lg, x2Ref=%lg, nRootsRef=%d\n",
                numTest,roots[0],roots[1],nRoots,refer->x1,refer->x2,refer->nRootsRef);
        return 0;

}


