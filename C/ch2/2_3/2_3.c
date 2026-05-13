#include<stdio.h>
#define MINS_PER_HR 60

int main(void){
    int hour, minute;
    double convertTime, temper;
    
    printf("How long it has been since the start of the power failure in whole hours and minutes> ");
    scanf("%d %d", &hour, &minute);

    // convert time to hours and calculate temperature
    convertTime = hour + (double) minute / MINS_PER_HR;
    temper = (4*convertTime*convertTime/(convertTime+2))-20;

    printf("%lf", temper);

    return 0;
}