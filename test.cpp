#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#include "solver.h"

const char FILE_NAME[10] = "Utest.txt";

void auto_test()
{
    FILE *testFile;
    testFile = fopen(FILE_NAME, "r");


    int amount_tests = 0;
    fscanf(testFile, "%d", &amount_tests);
    int counter = 0;
    for (counter = 0; counter < amount_tests; counter++)
    {
        double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
        int right_num_roots = 0;
        fscanf(testFile,"%lg %lg %lg %d", &a, &b, &c, &right_num_roots);

        //0 means there are no possible solutions, -228 means it has an infinity amount

        int num_roots = solve_square_equation(a, b, c, &x1, &x2);
        if (right_num_roots == ROOTS_ZERO || right_num_roots == ROOTS_INFINITY)
        {
            if (num_roots != right_num_roots)
            {
                printf("%lg%lg%lg%lg%lg",a,b,c,x1,x2);
                printf("FAILED:   num_roots = %d, x1 = %lg, x2 = %lg\n"
                       "EXPECTED: num_roots = %d\n"
                       "Test %d\n",
                       num_roots, x1, x2, right_num_roots, counter+1);
            }
            else
                printf("Test %d has an successful result!\n", counter+1);
        }
        else
        {
            double right_x1 = 0, right_x2 = 0;
            fscanf(testFile,"%lg %lg", &right_x2, &right_x1);

            sort_roots(&right_x2,&right_x1);
            if (!(double_equal_double(right_x1,x1) && double_equal_double(right_x2,x2)))
            {
                printf("FAILED: num_roots = %d, x1 = %lg, x2 = %lg\n"
                           "EXPECTED: num_roots = %d, x1 = %lg, x2 = %lg\n"
                           "test %d\n",
                           num_roots, x1, x2, right_num_roots, right_x1, right_x2, counter);
            }
            else
                printf("Test %d has an successful result!\n", counter+1);
        }
    }

    fclose(testFile);
}

