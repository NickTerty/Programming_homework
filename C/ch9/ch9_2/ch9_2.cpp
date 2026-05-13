#include<stdio.h>
#include<string.h>
#include <ctype.h> // for isalpha
#define MAX_N 100

int isPalindrome(char str[], int len){
    //Case 1: If the string is a characher or null.
    if(len <= 1){
        return 1;
    }
    //case 2: If the string is 2 charachers or more.
    else{
        if(str[0] == str[len - 1]){
            return isPalindrome(str + 1, len - 2);
        }
        else{
            return 0;
        }
    }
}

int main(void){
    char str[MAX_N]; // string
    char clean_str[MAX_N];
    int len; // the length of string

    int true_value;

    printf("Enter your string to check it is padlindrome: ");
    
    fgets(str, MAX_N, stdin);

    int j = 0; // index of clean_str
    for(int i = 0; str[i] != '\0'; i++){
        if(isalpha(str[i])){
            //if yes, turn it to lowercase
            clean_str[j] = tolower(str[i]);
            j++; 
        }
    }
    clean_str[j] = '\0';

    printf("Debug: Cleaned string is: %s\n", clean_str);
    
    len = strlen(clean_str);
    true_value = isPalindrome(clean_str, len);

    if(true_value == 1){
        printf("It is palindrome.\n");
    }
    else{
        printf("It is not palindrome.\n");
    }

    return 0;
}