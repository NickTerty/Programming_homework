#include<stdio.h>

int main(void){
    // inputs - UPC digit code
    int digits[12] = { 0 };
    int checkDigit = 0;

    // Prompts the user to enter the 12 digit(valid)
    printf("Enter the 12 digits of a barcode separated by spaces>\n");
    for(int i = 0; i < 12; i++){
        scanf("%d", &digits[i]);
    }

    // Check the barcode is valid or not
    /*Step
    1. and 2. 3 *(sum of odd numbered position) + (sum of even numbered position) 
    3. If the last digit of result from 1. is 0, then checkDigit == 1 is valid
        if(Result % 10 == 0)...

        Otherwise, 10 - (Result % 10) == checkDigit
    4. If digit[11] == checkDigit, then UPC is correct.
    */
    // Step 1 & 2
    int sum = 0;
    for(int i = 0; i < 11; i+=2){ // digit[0 + 2i] is odd numbered position 
        sum += digits[i];
    }
    sum = sum * 3;
    printf("The result of step 1 is %d\n", sum);

    for(int i = 1; i < 11; i+=2){
        sum += digits[i];
    }
    printf("The result of step 2 is %d\n", sum);

    //Step 3
    checkDigit = sum % 10;
    if(checkDigit != 0){
        checkDigit = 10 - checkDigit;
    }
    printf("The check digit of barcode is %d\n", checkDigit);

    //Step 4
    if(checkDigit == digits[11]){
        for(int i = 0; i < 12; i++){
            printf("%d ", digits[i]);
        }
        printf("\nvalidated\n");
    }
    else{
        for(int i = 0; i < 12; i++){
            printf("%d ", digits[i]);
        }
        printf("\nerror in barcode\n");
    }
    
    return 0;
}