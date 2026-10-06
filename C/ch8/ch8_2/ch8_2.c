#include<stdio.h>
#include<string.h>
#include<math.h>
#define NOT_FOUND -1

char COLOR_CODES[10][7] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white"};

int search(char colors[]){
    for(int i = 0; i < 10; i++){
        if(strcmp(colors, COLOR_CODES[i]) == 0){
            return i;
        }
    }

    return NOT_FOUND;
}

void resistEvaluate(){
    //input - 3 colors
    char colors[3][7];

    //Parameters - Colors index, decode willing 
    int colorIndex[3];
    int colorErr = 0; // 0 for false, 1 for true.
    int errIndex;

    //output - Resistance value
    double resistValue;

    printf("Enter the colors of the resistor's three bands,\n");
    printf("beginning with the band nearest the end.\n");
    printf("Type the colors in lowercase letters only, NO CAPS.\n");

    //input the color and scan the color is valid or not
    for(int i = 0; i < 3; i++){
        printf("Band %d => ", i+1);
        scanf("%s", colors[i]);
        colorIndex[i] = search(colors[i]);
        if(colorIndex[i] == NOT_FOUND){
            colorErr = 1;
            errIndex = i;
        }
    }

    //determine whether there exists a colorIndex is NOT_FOUND or not
    if(!colorErr){
        resistValue = (colorIndex[0] * 10 + colorIndex[1]) * pow(10, colorIndex[2]) / 1000.0;
        printf("Resistance value: %.2lf kilo-ohms\n", resistValue);
    }
    else{
        printf("Invalid color: %s\n", colors[errIndex]);
    }
}

int main(void){
    // input - whether decode another or not
    char decode_or_not = 'y';
    
    //Operating first time
    resistEvaluate();

    //Check whether decode another or not
    printf("Do you want to decode another resistor?\n=> ");

    while (scanf(" %c", &decode_or_not) && decode_or_not == 'y'){
        resistEvaluate();
        printf("Do you want to decode another resistor?\n=> ");
    }

    return 0;

}