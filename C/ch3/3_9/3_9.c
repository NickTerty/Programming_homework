#include <stdio.h>
#include <math.h>

void Cases(int day){
    int cases=0;

    //Calculate the cases with the model.
    cases = 40000 / (1+39999*(pow(exp(1), ((-0.24681*day)))));

    //Output the day and case calculated by model.
    printf("By day %d, model predict %d cases total.\n", day, cases);
}

int main(void){
    int day_1=0, day_2=0, day_3=0;

    printf("FLU EPIDEMIC PREDICTIONS BASED ON ELAPSED DAYS SINCE FIRST CASE REPORT\n");
    printf("Enter day number>> ");
    scanf("%d", &day_1);
    Cases(day_1);

    printf("Enter day number>> ");
    scanf("%d", &day_2);
    Cases(day_2);

    printf("Enter day number>> ");
    scanf("%d", &day_3);
    Cases(day_3);

    return 0;
}