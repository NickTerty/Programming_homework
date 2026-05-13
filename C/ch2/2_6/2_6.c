#include<stdio.h>

int main(void){
    char grade;
    double miniAve, curAve;
    int percent;

    printf("Enter desired grade> ");
    scanf("%c", &grade);
    printf("Enter minimum average required> ");
    scanf("%lf", &miniAve);
    printf("Enter current agerage in course> ");
    scanf("%lf", &curAve);
    printf("Enter how much the final counts as a percentage of the course grade> ");
    scanf("%d", &percent);

    double final_percent = percent / 100.0;
    double targetScore = (miniAve - curAve * (1 - final_percent)) / final_percent;

    printf("You need a score of %lf on the final to get a %c.\n", targetScore, grade);

    return 0;
    
}