#include <stdio.h>
#include <cassert>

#include "ProgramTesting.h"
#include "InOutPut.h"
#include "ZeroComparison.h"


void Hello(){

    printf("Hello! I'm a program that solves a quadratic equation.\nDo I need to run a test to verify the program?\n");

    if(getchar()=='y')
        testAll();

    clearBuffer();

}


void testAll(){

    const int nTests=5;

    TestData allData[nTests]={ {0,0,0,0,0,INF_ROOTS},
                               {1,0,-4,-2,2,TWO_ROOTS},
                               {0,0,5,0,0,NO_ROOTS},
                               {1,-4,4,2,2,ONE_ROOTS},
                               {0,-2,5,2.5,0,ONE_ROOTS}  };

    int nOK=0;

        for(int i=0;i<nTests;i++)
            nOK+=simpleTest(&allData[i],i+1);

    if(nOK==nTests)
        printf("All tests passed successfully\n");

}

int simpleTest(const TestData * refer, int numTest){

    assert(refer != NULL);

    const int sizesizeCoeffsRef=3;
    double coeffsRef[sizesizeCoeffsRef]={refer->a,refer->b,refer->c};

    const int sizeRootsRef=2;
    double roots_proverka[sizeRootsRef]={};

    Number_of_decisions nRoots = solveSquare (coeffsRef,roots_proverka);

    if( ( (zeroComparison(roots_proverka[0]-(refer->x1))==0 && zeroComparison(roots_proverka[1]-(refer->x2))==0) ||
        (zeroComparison(roots_proverka[0]-(refer->x2))==0 && zeroComparison(roots_proverka[1]-(refer->x1))==0) ) &&
        nRoots==refer->nRootsRef)

        return 1;

    else
        printf("FAILED %d Test: x1=%lg, x2=%lg, nRoots=%d\nexpected: x1Ref=%lg, x2Ref=%lg, nRootsRef=%d\n",
                numTest,roots_proverka[0],roots_proverka[1],nRoots,refer->x1,refer->x2,refer->nRootsRef);
        return 0;

}
