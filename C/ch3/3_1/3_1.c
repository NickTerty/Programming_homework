#include <stdio.h>
#include <math.h>

//Build a function to calculate monthly payment
double payments(double principal, int annual_rate, int num){
    double payment = 0;
    double month_rate = (annual_rate / 100.0) / 12.0;
    payment =  (month_rate * principal) / (double)(1-1/pow((1+month_rate), num));
    return payment;
}

int main(void){
    double principal = 0;
    int annual_rate = 0;
    int num = 0;

    double payment; //monthly payment

    //All inputs
    printf("Enter your amount that you borrow: ");
    scanf("%lf", &principal);
    printf("Enter the annual interest rate: ");
    scanf("%d", &annual_rate);
    printf("Enter your total number of payment(usually 36, 48, or 60): ");
    scanf("%d", &num);

    //calculate monthly payment
    payment = payments(principal, annual_rate, num);

    //The output
    printf("You need to pay $%.2lf every month.", payment);

    return 0;
}