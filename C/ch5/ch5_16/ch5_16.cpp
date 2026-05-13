#include<stdio.h>
#include<math.h>
#define SENTINEL 100
#define TOLERANCE 0.000001

/* build function
1. f(x)=x^n-c (pow(x, n)-c)
2. f'(x)=n*x^(n-1) (n*pow(x, n-1))
*/
double function(int power, int constant, double variable){
    return (pow(variable, power) - constant);
}

double derivFunction(int power, double variable){
    return (power * pow(variable, power - 1));
}

// main function
int main(void){
    // input - the power of x and constant(c) such that x^n-c=0
    int power = 0, constant = 0;

    // Running needed - stop after 100 times if it haven't done
    int count = 0;

    // asking user to input pow and constnt
    printf("Enter the power of x (as n) and the constant (as c) such that x^n-c=0> ");
    scanf("%d %d", &power, &constant);

    //Set the initial of x as the half of constant
    double testRoot_x = constant / 2.0;

    while(count < SENTINEL){
        if( fabs(function(power, constant, testRoot_x)) < TOLERANCE){
            break; // End the while looping, no matter whether count is equal to SENTINEL or not.
        }

        //Newton Method
        testRoot_x = testRoot_x - function(power, constant, testRoot_x) / derivFunction (power, testRoot_x);
        count++;
    }

    if( count < SENTINEL ){
        printf("If x is near to %.6lf, then there will be an approximated root. (tried %d times)\n", testRoot_x, count);
    }
    else{
        printf("I can't find the root of function.");
    }

    return 0;

}