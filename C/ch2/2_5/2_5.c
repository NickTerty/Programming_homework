#include<stdio.h>
#define MIN_PER_HR 60

int main(void){
    int VTBI, minPerInfus;
    double rate;
    
    printf("Volume to be infused (ml) => ");
    scanf("%d", &VTBI);

    printf("Minutes over which to infuse => ");
    scanf("%d", &minPerInfus);

    rate = (double) VTBI / minPerInfus * MIN_PER_HR;

    printf("VTBI: %d ml\n", VTBI);
    printf("Rat: %lf ml/hr\n", rate);

}