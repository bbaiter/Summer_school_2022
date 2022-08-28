#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED

enum NumRoots_t {
    ROOTS_ZERO = 0,
    ROOTS_ONE = 1,
    ROOTS_TWO = 2,
    ROOTS_INFINITY = -228
};

void roots_output(int num_roots, double x1, double x2);
bool double_equal_double(double x, double y);
double atof (char s[]);
bool is_number(char s[]);
void input_num(double* x);
int linear_equation(double b, double c, double* x1);
int solve_square_equation(double a, double b, double c,
                          double* x1, double* x2);

void sort_roots(double* right_x2, double* right_x1);



#endif


