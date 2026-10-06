#include<stdio.h>

int isDivBy9(int num){
    int sum = 0;
    while(num != 0){
        sum = sum + (num % 10);
        num = num / 10;
    }

    if(sum % 9 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void){
    int num = 0, result = 0;
    printf("Enter your number: ");
    scanf("%d", &num);

    result = isDivBy9(num);

    if(result == 1){
        printf("It is divisible by 9."); // 154368, 621594
    }
    else{
        printf("It is not divisible by 9."); //123456
    }

    return 0;
}