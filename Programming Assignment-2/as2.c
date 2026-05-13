//This program is to find the x values using the quadratic formula (also solves linear equations). Created by Ryan Ramdihal-Assignment 2//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#ifdef _MSC_BUILD // We're on a Microsoft compiler.
#define strcasecmp stricmp // We don't have strcasecmp, we have stricmp.
#endif
void remove_crlf(char *s)
{
char *t = s + strlen(s);
// t begins at the null sentinel at the end of s.
t--;
/* t is now at the last character of s - unless s didn't contain any characters,
in
which case, t is now *BEFORE* s. We have to keep checking for that. */
/* We repeat until EITHER t slides to the left of s, OR we find a character that
is
not a line feed (\n) or a carriage return (\r). */
while ((t >= s) && (*t == '\n' || *t == '\r'))
{
*t = '\0'; // Clobber the character t is pointing at.
t--; // Decrement t.
}
}
/* This function determines the value of x when a = 0 and c is positive*/
double c_is_positive (double b, double c)
{
double if_a0_c_positive = - c / b;
printf("x equals %lf\n", if_a0_c_positive);
return if_a0_c_positive; /* Returns the final answer if a = 0 and c is positive.
*/
}
/* This function determines the value of x when a = 0 and c is negative*/
double c_is_negative (double b, double c)
{
double if_a0_c_negative = (-1 * c )/ b;
printf("x equals %lf\n", if_a0_c_negative);
return if_a0_c_negative; /* Returns the final answer if a = 0 and c is
negative. */
}
/* This function determines the value of x when a = 0 and both, b and c, are
negative*/
double b_and_c_negative (double b, double c)
{
double if_b_and_c_negative = c / - b;
printf("x equals %lf\n",if_b_and_c_negative);
return if_b_and_c_negative; /* Returns the final answer if a = 0,and b and c
are negative. */
}
/* This function is when a = 0 (condition set in main), this calls the conditional
functions made above*/
double a_equals_zero (double b, double c)
{
if (c > 0)
{
c_is_positive(b,c);
}
else if (c < 0 && b < 0)
{
b_and_c_negative(b,c);
}
else if (c < 0)
{
c_is_negative(b,c);
}
return 0;
}
/* This function determines the value of the discriminant (Assigned to "discrim" in
main) */
double discriminant(double a, double b, double c)
{
double discriminant = (b * b) - (4 * a * c);
return discriminant; /* Returns discriminant, to determine which if statement to
use depending on the sign the discriminant value has */
}
/* Function that finds the last term in the complex quadratic equation (negative
discriminant) This is the "b" term in a+-bi. (Assigned to "xi_back" in main) */
double back_roots_of_x(double a,double discriminant)
{
double xi_back = sqrt(fabs(discriminant)) / (2 * a);
return xi_back; /* Returns the second term in the final answer if the
discriminant is negative */
}
/* Function that finds the first term in the complex quadratic equation (negative
discriminant). This is the "a" term in a+-bi. (Assigned to "xi_front" in main) */
double front_roots_of_x (double a,double b)
{
double xi_front= (-b) / (2 * a);
return xi_front; /* Returns the first term in the final answer if the
discriminant is negative */
}
/*Function to find the plus value of quadratic equation for positive values of
discriminant. (Assigned to "x1" in main) */
double real_x1_root (double a, double b, double discriminant)
{
double x1 = ((-b) + sqrt(discriminant)) / (2 * a);
return x1; /* Returns the first root/answer if the discriminant is positive. */
}
/*Function to find the plus value of quadratic equation for positive values of
discriminant. (Assigned to "x2" in main) */
double real_x2_root (double a, double b, double discriminant)
{
double x2 = ((-b) - sqrt(discriminant)) / (2 * a);
return x2; /* Returns the second answer if the discriminant is positive. */
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
char a_value[128]; /* Declared a_value, b_value, and c_value character string to
a,b, and c*/
char b_value[128];
char c_value[128];
char new_value_yes_no[128]; /* Declared the string input value for whether the
user wants to input new values*/
double a; /* Declared a,b,and c to assign to a_value,b_value, and
c_value character string. */
double b;
double c;
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
while (1) /* While loop to reset new values if answered yes to new_value_yes_no
string*/
{
printf("What is the value of a?"); /* Asks the user for the a value,
then inputs the number the user sets, and defines it to a variable*/
fgets(a_value,127,stdin);
a = atof(a_value);
printf("The value of a equals %lf\n",a);
printf("What is the value of b?"); /* Asks the user for the b value,
then inputs the number the user sets, and defines it to b variable*/
fgets(b_value,127,stdin);
b = atof(b_value);
printf("The value of b equals %lf\n",b);
printf("What is the value of c?"); /* Asks the user for the c value,
then inputs the number the user sets, and defines it to c variable*/
fgets(c_value,127,stdin);
c = atof(c_value);
printf("The value of c equals %lf\n",c);
discrim = discriminant (a,b,c);
x1 = real_x1_root(a,b,discrim); /* Assigned x1 to real_x1_root function when
(discrim > 0) */
x2 = real_x2_root(a,b,discrim); /* Assigned x2 to real_x2_root function when
(discrim > 0) */
xi_front = front_roots_of_x (a,b); /* Assigned xi_front to front_roots_of_x
function when (discrim < 0) */
xi_back = back_roots_of_x (a,discrim); /* Assigned xi_back to back_roots_of_x
function when (discrim < 0)*/
x_zero = zero_discriminant (a,b); /* Assigned x_zero to zero_discriminant
function */
if (a == 0)
{
a_equals_zero(b,c); /* Function called for if a=0 . Its seperate functions
explained above main */
}
else if (discrim > 0)
{
printf("The roots of x are %lf and %lf.\n", x1,x2); /*Final print statement
for x1 and x2.*/
}
else if (discrim < 0)
{
printf("The value of x1 is %lf + %lfi.\n", xi_front,xi_back); /*Final print
statement for xi_front and back.*/
printf("The value of x2 is %lf - %lfi.\n", xi_front,xi_back);
}
else if (discrim == 0)
{
printf("The value of x is %lf.\n", x_zero); /*Final print statement for if the
discriminant = 0.*/
}
while(1) /* Loop if the answer to new_value_yes_no is not "yes" or "no", for
the user to try again with a correct input*/
{
printf(" Would you like to set new values? (Answer: yes/no)");
fgets(new_value_yes_no,127,stdin);
remove_crlf(new_value_yes_no);
if (strcasecmp(new_value_yes_no, "yes")== 0) /* If the user's answer is "yes"
the program will loop from the beginning*/
{
break;
}
else if(strcasecmp(new_value_yes_no, "no")== 0)
{
printf("Okay!You've reached the end of the program. \n");
break; /* Breaks out of the inner loop if the yes/no input was correct*/
}
else
{
printf("That is an incorrect input. Try again.\n"); /* Loops back to the
question, whether the user wants to set new values until they use the correct
input. */
}
}
if (strcasecmp(new_value_yes_no, "no")== 0)
{
break; /*Seperate if statement that breaks out of the outer loop if the
input was "no" to the new value question. */
}
}
return 0;
}
