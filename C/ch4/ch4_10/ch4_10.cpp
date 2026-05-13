#include<stdio.h>

void timeDisplay(void){
    printf("Bread Time Chart\n");
    printf("(Operation): (time for White Bread) and (time for Sweet Bread)\n\n");
    printf("Primary kneading: 15 mins and 20 mins\n");
    printf("Primary rising: 60 mins and 60 mins\n");
    printf("Secondary kneading: 18 mins and 33 mins\n");
    printf("Secondary rising: 20 mins and 30 mins\n");
    printf("Loaf shaping: 2 seconds and 2 seconds\n");
    printf("Final rising: 75 mins and 75 mins\n");
    printf("Baking: 45 mins and 35 mins\n");
    printf("Cooling: 30 mins and 30 mins\n\n");
}

void bakingTime(char bread, int sizeDouble, int manualBaking){
    int min = 0;
    int sec = 0;
    if(manualBaking == 0){
        if(bread == 'W'){
            min = 15 + 60 + 18 + 20 + 75 + 30;
            sec = 2; 
            if(sizeDouble == 0){
                min = min + 45;
                printf("The baking time is %d mins %d secs\n", min, sec);
            }
            else if(sizeDouble == 1){
                min = min + 45 * 1.5;
                sec = sec + 30;// 45*1.5=67.5(mins)
                printf("The baking time is %d mins %d secs\n", min, sec);
            }
            else{
                printf("Your type of loaf size is wrong, please try again.\n");
            }
        }
        else if (bread == 'S'){ //bread is sweet(S)
            min = 20 + 60 + 33 + 30 + 75 + 30;
            sec = 2; 
            if(sizeDouble == 0){
                min = min + 35;
                printf("The baking time is %d mins %d secs\n", min, sec);
            }
            else if(sizeDouble == 1){
                min = min + 35 * 1.5;
                sec = sec + 30;// 35*1.5=52.5(mins)
                printf("The baking time is %d mins %d secs\n", min, sec);
            }
            else{
                printf("Your type of loaf size is wrong, please try again.\n");
            }
        }
        else{
            printf("Your type of bread is wrong, please try again.\n");
        }
    }
    else if(manualBaking == 1){
        if(bread == 'W'){
            min = 15 + 60 + 18 + 20;
            sec = 2;
            printf("The baking time is %d mins %d secs\n", min, sec);
            printf("And now, remove the dough for manual baking.\n");
        }
        else if (bread == 'S'){ //bread is sweet(S)
            min = 20 + 60 + 33 + 30;
            sec = 2;
            printf("The baking time is %d mins %d secs\n", min, sec);
            printf("And now, remove the dough for manual baking.\n");
        }
        else{
            printf("Your type of bread is wrong, please try again.\n");
        }
    }
    else{
        printf("Your type of manual baking is wrong, please try again.\n");
    }
}


int main(void){
    //data
    int sizeDouble = 0, manualBaking = 0;
    char bread;

    //Display a statement for each step.
    timeDisplay();

    //input the type of bread as W for White and S for Sweet.
    printf("Enter the type of bread as W for White and S for Sweet> ");
    scanf("%c", &bread);

    //if the loaf size is double and if the baking is manual.
    printf("Is the loaf size double?(Enter 1 for yes or 0 for no)> ");
    scanf("%d", &sizeDouble);
    printf("Do you want to bake in manual?(Enter 1 for yes or 0 for no)> ");
    scanf("%d", &manualBaking);

    //Calculate the baking (including manual baking instruction)
    bakingTime(bread, sizeDouble, manualBaking);

    return 0;
}