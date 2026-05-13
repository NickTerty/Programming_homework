#include<stdio.h>
#include<math.h>

// trapezoidal rule
double trap(double a, double b, int n, double f(double x)){
    double area;

    double h = (double) ( b - a ) / (double) n;
    
    double sum = 0;

    for(int i = 1; i < n; i++){
        double x_i = a + i * h; 
        sum += f(x_i);
    }

    area = (h / 2) * ( f(a) + f(b) + 2 * sum );

    return area;
    
}

// function g and h
double g(double x){
    return x * x * sin(x);
}

double h(double x){
    return sqrt(4 - x * x);
}

int main(void){
    // input - a and b 
    double a = 0, b = 0;

    // output - area of g and h
    double area_g, area_h;

    // error between circle and h(x)
    double error;

    // Asking for input a and b for g(x)
    printf("Enter the a and b for the function g(x) = x * x * sin(x)> ");
    scanf("%lf %lf", &a, &b);

    // Calculate the area of g(x)
    for(int n = 2; n <= 128 ; n *= 2){
        area_g = trap(a, b, n, g);

        printf("n = %d, T_g = %.6lf\n", n, area_g);
    }

    // Asking for input a and b for h(x)
    printf("Enter the a and b for the function h(x) = sqrt(4 - x * x)> ");
    scanf("%lf %lf", &a, &b);

    // Calculate the area of h(x)
    for(int n = 2; n <= 128 ; n *= 2){
        area_h = trap(a, b, n, h);
        error = area_h - 2 * M_PI; // M_PI in math.h as 3.1415926......

        printf("n = %d, T_h = %.6lf, error = %.6lf\n", n, area_h, error);
    }

    return 0;
}