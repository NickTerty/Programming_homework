#include <stdio.h>

//Define the funciton to print the word connected the letter
void content(char color){
    if(color == 'O' || color =='o'){
        printf("ammonia");
    }
    else if(color == 'B' || color == 'b'){
        printf("carbon monoxide");
    }
    else if(color == 'Y' || color == 'y'){
        printf("hydrogen");
    }
    else if(color == 'G' || color == 'g'){
        printf("oxygen");
    }
    else{
        printf("Contents unknown");
    }
}

int main(void){
    char color;
    
    //input the color letter
    printf("Enter the letter of color that you observe> ");
    scanf("%c", &color);
    
    content(color);
    
    return 0;
}
