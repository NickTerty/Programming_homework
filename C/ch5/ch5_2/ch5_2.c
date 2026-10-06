#include<stdio.h>
#define SENTINEL 

int main(void){
    // input - Reading each digit of number
    char digit = 0;
    // process - We need test char into int
    int value = 0;
    // output - sum form all digits
    int sum = 0;

    printf("Enter all digits of the number> ");
    scanf("%c", &digit);
    
    while(  digit != '\n' ){
        printf("%c\n", digit); 

        value = (int)digit - (int)'0';      
        sum += value;

        scanf("%c", &digit);
    }

    printf("The sum is %d", sum);

    return 0;
}