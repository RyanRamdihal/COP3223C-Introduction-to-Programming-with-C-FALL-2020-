#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* This function determines the value of the discriminant (Assigned to "discrim" in
main) */
double discriminant(double a, double b, double c)
{
double discriminant = (b * b) - (4 * a * c);
return discriminant;
}
/* Function that finds the last term in the complex quadratic equation (negative
discriminant) This is the "b" term in a+-bi. (Assigned to "xi_back" in main) */
double back_roots_of_x(double a,double discriminant)
{
double xi_back = sqrt(fabs(discriminant)) / (2 * a);
return xi_back;
}
/* Function that finds the first term in the complex quadratic equation (negative
discriminant). This is the "a" term in a+-bi. (Assigned to "xi_front" in main) */
double front_roots_of_x (double a,double b)
{
double xi_front= (-b / (2 * a));
return xi_front;
}
/*Function to find the plus value of quadratic equation for positive values of
discriminant. (Assigned to "x1" in main) */
double real_x1_root (double a, double b, double discriminant)
{
double x1 = ((-b) + sqrt(discriminant)) / (2 * a);
return x1;
}
/*Function to find the plus value of quadratic equation for positive values of
discriminant. (Assigned to "x2" in main) */
double real_x2_root (double a, double b, double discriminant)
{
double x2 = ((-b) - sqrt(discriminant)) / (2 * a);
return x2;
}
/*Function to find the minus value of quadratic equation for positive values of
discriminant. (Assigned to "x_zero" in main)*/
double zero_discriminant (double a,double b)
{
double zero_root;
zero_root= - b / (2 * a);
return zero_root;
}
int main (void)
{
double a = 2; /* Assign values as needed to a,b,and c in main. */
double b = 6;
double c = 8;
double discrim; /* Declared discrim variable to later assign to
discriminant function */
double x1; /* Declared x1 variable to later assign to real_x1_root
function */
double x2; /* Declared x2 variable to later assign to real_x2_root */
double xi_front; /* Declared xi_front variable to later assign to
front_roots_of_x function */
double xi_back; /* Declared xi_back variable to later assign to
back_roots_of_x function */
double x_zero; /* Declared x_zero variable to later assign to
zero_discriminant function */
discrim = discriminant (a,b,c);
if (discrim > 0)
{
x1 = real_x1_root(a,b,discrim); /* Assigned x1 to real_x1_root function */
x2 = real_x2_root(a,b,discrim); /* Assigned x2 to real_x2_root function */
printf("The roots of x are %lf and %lf.\n", x1,x2);
}
else if (discrim < 0)
{
xi_front = front_roots_of_x (a,b); /* Assigned xi_front to front_roots_of_x
function */
xi_back = back_roots_of_x (a,discrim); /* Assigned xi_back to back_roots_of_x
function */
printf("The value of x1 is %lf + %lfi.\n", xi_front,xi_back);
printf("The value of x2 is %lf - %lfi.\n", xi_front,xi_back);
}
else if (discrim == 0)
{
x_zero = zero_discriminant (a,b); /* Assigned x_zero to zero_discriminant
function */
printf("The value of x is %lf.\n", x_zero);
}
return 0;
}

