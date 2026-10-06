#include<stdio.h>

int within_x_percent(int ref, double data, int percent){
    double min, max;
    
    min = ref - (percent / 100.0) * ref;
    max = ref + (percent / 100.0) * ref;

    if((min <= data) && (data <= max)){
        return 1;
    }
    else{
        return 0;
    }
}

void subTest(int ref, double data, int percent){
    if(within_x_percent(ref, data, percent) == 1){
        switch (ref)
        {
        case 100:
            printf("Substance is water.\n");
            break;
        
        case 357:
            printf("Substance is mercury.\n");
            break;
        
        case 1187:
            printf("Substance is copper.\n");
            break;

        case 2193:
            printf("Substance is silver.\n");
            break;
        
        case 2660:
            printf("Substance is gold.\n");
            break;
        
        default:
            break;
        }
    }
    else{
        printf("Substance unknown\n");
    }
}

int main(){
    int ref = 0, percent = 0;
    double data = 0;

    int returnValue = 0;

    //Define percent is 5 for problem request
    percent = 5;

    printf("Enter the boiling point of the substance in °C that you observed> ");
    scanf("%lf", &data);
    printf("Enter the boiling point as parameters> ");
    scanf("%d", &ref);

    //call the within_x_percent
    returnValue = within_x_percent(ref, data, percent);

    //Test the substance
    subTest(ref, data, percent);

    return 0;
}