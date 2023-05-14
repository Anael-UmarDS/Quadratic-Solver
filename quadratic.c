/* This program can solve quadratics */

#include <stdio.h>
#include <math.h>
#include <string.h>

/* The function below calculates the discriminant of with given paramters of integers a, b, c */

int discriminant_calculate(int a, int b, int c)
{
    int discriminant;
    discriminant = pow(b, 2) - (4 * a * c);
    return discriminant;
}

/* The function below calculates the root of a quadratic equation by using the quadratic formula */
double quadratic_formula(int a, int b, int c, char desired[11])
{
    /* Define integer varibale discriminant with value returned by calling disciminant_calculate of a, b, c*/
    int discriminant = discriminant_calculate(a, b, c);

    /* Use Quadratic Formula */
    double factor_one = (-b + sqrt(discriminant)) / (2.0 * a);
    double factor_two = (-b - sqrt(discriminant)) / (2.0 * a);
    
    /* Return root based on desired root */
    if(strcmp(desired, "factor_one") == 0)
    {
        return factor_one;
    }
    else
    {
        return factor_two;
    }
}

/* The function below checks the discriminant of a quadratic equation to check if there are any real roots */
void discriminant_check(int a, int b, int c)
{
    /* Define integer disciminant and character answer with upto 11 characters */
    int discriminant;
    char answer[11];

    /* Calculate discriminant of a, b, c */
    discriminant = discriminant_calculate(a, b, c);

    /* Print the number of real roots based on discriminant */
    if(discriminant > 0)
    {
        printf("\nThere are 2 distinct real roots\n");
    }
    else if(discriminant < 0)
    {
        printf("\nThere are no real roots\n");
    }
    else
    {
        printf("\nThere is 1 real root\n");
    }
    /* Ask user if they want to see the roots */
    printf("Do you want to see what the roots are(y or n)?\n");
    scanf("%s", answer);
    if(strcmp(answer, "y") == 0)
    {
        /* Solve for the roots */
        double root_one = quadratic_formula(a, b, c, "factor_one");
        double root_two = quadratic_formula(a, b, c, "factor_two");
        
        printf("\nRoot One is %lf\n", root_one);
        printf("Root Two is %lf\n", root_two);
    }
    else
    {
        /* Else just say goodbye */
        printf("\nThank You For Choosing Us!\n");
    }
}

/* This function solves or checks a quadratic equation based on user inputs */
void quadratic_solver(int a, int b, int c)
{
    /* Define character answer with upto 11 characters*/
    char answer[11];

    /* Ask user for answer */
    printf("Do you want to check if there is a solution available or solve a quadratic (c for check, s for solve)?\n");
    scanf("%s", answer);
    if(strcmp(answer, "c") == 0)
    {
        /* Check for disciminant and print the number of real roots by calling discriminant_check */
        discriminant_check(a, b, c);
    }
    else if(strcmp(answer, "s") == 0)
    {
        /* Add the code to solve the quadratic */
        double factor_one = quadratic_formula(a, b, c, "factor_one");
        double factor_two = quadratic_formula(a, b, c, "factor_two");
        printf("\nFactor one is: %lf\n", factor_one);
        printf("Factor two is: %lf\n", factor_two);
        printf("\nThank You For Choosing Us!\n");

    }
    else
    {
        /* If choice not valid, use recursive loop to call quadratic_solver again until it is a valid option */
        printf("Invalid choice\n");
        quadratic_solver(a, b, c);
    }
}

/* Take user inputs and solve or check based on inputs by calling quadratic_solver */
int main()
{
    /* Define integers a, b, c which represent the coefficients of a quadratic equation */
    int a, b, c;
    printf("\nWelcome to the Quadratic Equation Solver\n\n");
    printf("The standard form of a quadratic equation is ax^2 + bx + c = 0\n");
    printf("\nPlease enter the coefficients below:\n");
    printf("\nPlease enter a:\n");
    scanf("%d", &a);
    printf("Please enter b:\n");
    scanf("%d",&b);
    printf("Please enter c:\n");
    scanf("%d",&c);

    printf("\n");

    quadratic_solver(a, b, c);
    return 0;
}