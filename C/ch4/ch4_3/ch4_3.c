#include<stdio.h>

int fun1(char input){
    if (input == 'T'){
        return 1;
    }
    else{
        return 0;
    }
}

int fun2(void){
    printf("fun2 executed\n");

    return 1;
}



int main(void){
    char input = 0;

    printf("Enter T for true or F for false> ");
    scanf("%c", &input);

    //Testing &&
    printf("Testing &&\n");
    if(fun1(input) && fun2()){
        printf("Test of && complete\n");
    }

    //Testing ||
    printf("Testing ||\n");
    if ((fun1(input)) || fun2()){
        printf("Test of || complete\n");
    }
    
    return 0;
}