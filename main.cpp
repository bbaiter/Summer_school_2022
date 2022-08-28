
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

const double EPS = 0.000001;

#include "test.h"
#include "solver.h"



int main()
{
    printf("Square equation solver\n"
           "Ilya Murashev 2022, Summer school\n");
    char key = 0;

    printf("Welcome to square equation solver!\n"
            "press 's' to solve an equation\n"
            "press 'e' to start tests\n"
            "press 'q' to quit\n");

    do
    {
        key = (char)getch();

        if (key == 's')
        {
            printf("Enter coefficients a, b, c to solve equation like ax^2+bx+c=0\n");

            double a = 0, b = 0, c = 0;
            input_num(&a);
            input_num(&b);
            input_num(&c);

            double x1 = 0, x2 = 0;
            int num_roots = solve_square_equation(a, b, c, &x1, &x2);

            roots_output(num_roots, x1, x2);

            printf("Choose next option using keyboard\n");
        }
        else if (key == 'e')
        {
            auto_test();
            printf("Choose next option using keyboard\n");
        }
        else if (key == 'q')
        {
            break;
        }
        else // (key != 's' && key != 'e' && key != 'q')
            printf("it is a wrong letter\nChoose the right one\n");

    } while (key!='q');

    printf("Thank you for using our application!\n");
}

