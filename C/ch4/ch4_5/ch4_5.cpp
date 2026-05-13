#include <stdio.h>

int charge(double user){
    int charges = 0;
    if(0 < user && user <= 1){
        charges = 250;
    }
    else if(1 < user && user <= 2){
        charges = 500;
    }
    else if(2 < user && user <= 5){
        charges = 1000;
    }
    else if(5 < user && user <= 10){
        charges = 1500;
    }
    else if(user > 10){
        charges = 2000;
    }
    else{
        return -1; //bad data
    }

    return charges;
}

int main(void){
    double user = 0;
    int charges= 0;

    printf("Enter the amount of data used by the subscriber> ");
    scanf("%d", &user);

    charges = charge(user);

    if(charges == -1){
        printf("Bad data.\n");
    }
    else{
        printf("The charge is %d.", charges);
    }

    return 0;
}
