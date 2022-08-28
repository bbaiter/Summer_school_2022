#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>




const double EPS = 0.000001;

enum NumRoots_t {
    ROOTS_ZERO = 0,
    ROOTS_ONE = 1,
    ROOTS_TWO = 2,
    ROOTS_INFINITY = -228
};

void roots_output(int num_roots, double x1, double x2)
{
    switch (num_roots)
    {
    case ROOTS_ZERO:
        printf("Equation doesn't have any roots\n");
        break;
    case ROOTS_ONE:
        printf("Equation has one root: %lg\n",x1);
        break;
    case ROOTS_TWO:
        printf("Equation has two roots: %lg and %lg\n",x1, x2);
        break;
    case ROOTS_INFINITY:
        printf("The number of roots is infinity\n");
        break;
    default :
        printf("Error\n");
    }
}

bool double_equal_double(double x, double y)
{
    return (fabs(x-y)<EPS);
}
bool is_number(char s[])
{
    int i = 0, counter = 0, dot_counter = 0, minus_counter = 0;
    int length = strlen(s);
    for (i = 0; i < length; i++)
    {
        if (s[i] == '.')
        {
            dot_counter++;
        }
        if (s[i] == '-')
        {
            minus_counter++;
        }
        if (isdigit(s[i]) || s[i] == '-' || s[i] == '+' || s[i] == '.')
        {
            counter++;
        }
    }
    if (counter == i && minus_counter < 2 && dot_counter < 2)
    {
        return true;
    }
    return false;
}

void input_num(double* x)
{
    char s_input[4000];
    do
    {
        scanf("%s",&s_input);
        bool rez = is_number(s_input);
        if (rez == 0)
        {
            printf("It is not a number. Please change last number\n");
        }
        else
        {
            *x = strtod(s_input,NULL);
        }
        if (rez == 1)
            {break;}

    } while (1);
}

int linear_equation(double b, double c, double* x1)
{
    if (double_equal_double(b,0))
    {
        return double_equal_double(c,0) ? ROOTS_INFINITY : ROOTS_ZERO;
    }
    else
    {
        *x1 = -c / b;
        return ROOTS_ONE;
    }
}

//----------------------------------------------------
//!@param [in] a a-coefficient
//!@param [in] b b-coefficient
//!@param [in] c c-coefficient
//!@param [out] x1 Pointer to the first root
//!@param [out] x2 Pointer to the Second root
//!
//!@return Number of roots
//!
//!@note In case of infinite number of roots
//!             returns ROOTS_INFINITY
//----------------------------------------------------

int solve_square_equation(double a, double b, double c,
                          double* x1, double* x2)
{
    if (double_equal_double(a,0))
        return linear_equation(b, c, x1);

    double discriminant = b*b - 4*a*c;
    if (discriminant < 0)
        return ROOTS_ZERO;

    if (double_equal_double(discriminant,0))
    {

        *x1 = (-b)/(2*a);
        *x2 = *x1;
        return ROOTS_ONE;
    }

    *x1 = (-b + sqrt(discriminant)) / (2*a);
    *x2 = (-b - sqrt(discriminant)) / (2*a);
    return ROOTS_TWO;
}

void sort_roots(double* right_x2, double* right_x1)
{
    if (*right_x1 < *right_x2)
    {
        double buffer = *right_x1;
        *right_x1 = *right_x2;
        *right_x2 = buffer;
    }

}
