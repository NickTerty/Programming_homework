#include<stdio.h>

int main(void){
    double begin, end;
    double traveledMiles, price;
    double rate = 1.50;

    printf("TAXI RATE CALCULATOR \n");

    //beginning odometer
    printf("Enter beginning odometer reading=> ");
    scanf("%lf", &begin);

    //ending odometer
    printf("Enter ending odometer reading=> ");
    scanf("%lf", &end);

    //calculate traveled miles and price(taxi fare)
    traveledMiles = end - begin;
    price = rate * traveledMiles;

    //output how many traveled miles and taxi fare
    printf("You traveled %.1lf miles. At $%.2lf per mile, your fare is $%.2lf.\n", traveledMiles, rate, price);

    return 0;
}