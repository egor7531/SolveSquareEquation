#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Options.h"
#include "ProgramTesting.h"

void help();

void test();

void Options(char * argv[],const int argc)
{
    printf("\n");

    for(int i=1;i<argc;i++)
    {
        if(!strcmp(argv[i],"--help"))

            help();

        else if(!strcmp(argv[i],"--test"))

            test();

        else
        {
            printf("There is no such command: %s\n",argv[i]);
            exit(1);
        }
    }
}

void help()
{
        printf("Options:\n");

        printf(" a.exe - A program that solves the square equation\n");

        printf(" --help - Display this information\n");

        printf(" --test - Run the program through unit tests\n");

        printf("\n");
}

void test()
{
    testAll();

    printf("\n");
}

