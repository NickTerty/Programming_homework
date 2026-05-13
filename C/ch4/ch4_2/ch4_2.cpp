#include<stdio.h>
#include<math.h>

double BMI(double weight, double height){
    double bodyMassIndex = 0;
    bodyMassIndex = (703 * weight) / (height * height);

    return bodyMassIndex;
}

void weightState(double bodyMassIndex){
    if (bodyMassIndex < 18.5){
        printf("You are underweight.");
    }
    else if ((18.5<= bodyMassIndex) && (bodyMassIndex <= 24.9)){
        printf("You are normal.");
    }
    else if ((25.0<= bodyMassIndex) && (bodyMassIndex <= 29.9)){
        printf("You are overweight.");
    }
    else {
        printf("You are obese");
    }
}

int main(void){
    double weight = 0, height = 0;
    double bodyMassIndex = 0;

    printf("Enter your weight in pounds> ");
    scanf("%lf", &weight);
    printf("Enter your height in inches> ");
    scanf("%lf", &height);

    bodyMassIndex = BMI(weight, height);

    printf("Your BMI is %.1lf. \n", bodyMassIndex);
    weightState(bodyMassIndex);

    return 0;
}
