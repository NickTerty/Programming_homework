#include<stdio.h>
#include<math.h>

int reverseNum(int num){
    int temp = 0, reverNum = 0;
    while (num != 0){
        temp = num % 10;
        num /= 10;
        reverNum = 10 * reverNum + temp;
    }

    return reverNum;
}

int isPrime(int num){

    if(num == 1){
        return 0;
    }

    for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            return 0;
        }        
    }
    return 1;
}

int isPalindrome(int num){
    int reverNum = reverseNum(num);
    
    if(num < 0){
        return 0;
    }

    if(num == reverNum){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void){
    int num;
    int reverNum, boolIsPrime, boolIsPalind;

    printf("Enter integer numbers(or 99999 as end)> ");
    scanf("%d", &num);

    while( num != 99999){
        reverNum = reverseNum(num);
        boolIsPrime = isPrime(num);
        boolIsPalind = isPalindrome(num);
        printf("Reverse number: %d\n", reverNum);
        
        printf("Is prime or not: ");
        if( boolIsPrime == 1 ){
            printf("Yes\n");
        } 
        else{
            printf("No\n");
        }

        printf("Is palindrome or not: ");
        if( boolIsPalind == 1 ){
            printf("Yes\n");
        } 
        else{
            printf("No\n");
        }

        printf("\nEnter integer numbers> ");
        scanf("%d", &num);
    }

    return 0;
}