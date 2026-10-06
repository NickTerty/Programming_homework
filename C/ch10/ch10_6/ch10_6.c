#include<stdio.h>
#include<string.h>
#define MAX_WORDS 100 
#define WORD_LEN 21
#define SENTINEL "ZZZ"

typedef struct{
    char language[WORD_LEN]; // component for the language of the words
    int count; //that keeps track of how many words are in the list
    char words[MAX_WORDS][WORD_LEN];
} wordList;

int contains(char target[WORD_LEN], wordList list){
    for(int i = 0; i < list.count; i++){
        if(strcmp(list.words[i], target) == 0){
            return 1; // it is found
        }
    }

    return 0; // find all but unfound
}

void add_word(char new_word[MAX_WORDS], wordList *list_ptr){
    if(list_ptr->count == MAX_WORDS){
        printf("List full, word not added.");
    }
    else{
        // If there is no other words are same, add this word.
        if(contains(new_word, *list_ptr) == 0){
            strcpy(list_ptr->words[list_ptr->count], new_word);
            list_ptr->count++;
        }
    }
}

void load_word_list(FILE* fin, wordList *list_ptr){
    char temp_word[WORD_LEN];

    if(fin == NULL){
        printf("Wrong: The file is null.\n");
        return;
    }

    // initialize the value
    list_ptr->count = 0;

    // Scan the language
    fscanf(fin, "%s", list_ptr->language);

    // Load the word to temp, worked by add_word 
    while(fscanf(fin, "%s", temp_word) != EOF){
        add_word(temp_word, list_ptr);
    }
}

int equal_lists(wordList list1, wordList list2){
    // failed when the language is different
    if(strcmp(list1.language, list2.language) != 0){
        return 0;
    }
    // failed when the total number is different
    if(list1.count != list2.count){
        return 0;
    }
    // Determine all words in list1 are equal to list2
    for(int i = 0; i < list1.count; i++){
        if(contains(list1.words[i], list2) == 0){
            return 0;
        }
    }

    return 1;
}

void display_word_list(wordList list){
    printf("The Language: %s\n", list.language);
    printf("Word numbers: %d\n", list.count);

    for(int i = 0; i < list.count; i++){
        printf("%-20s", list.words[i]);

        // newline per 4 words
        if((i + 1) % 4 == 0){
            printf("\n", list.words[i]);
        }
    }

    printf("\n-----------------\n");
}

int main(void){
    //File
    FILE* fin;
    //input
    wordList list1, list2;
    char word_find[WORD_LEN];
    char temp_word[WORD_LEN];

    fin = fopen("input.txt", "r");

    // --- 1: Scan the file as list1 ---
    load_word_list(fin, &list1);
    printf("List 1 loaded from file.\n");

    // --- 2: Enter List 2 by user (Language + 12 words) ---
    list2.count = 0; // Initialization
    printf("\nCreate List 2.\nEnter Language: ");
    scanf("%s", list2.language);

    printf("Enter 12 words for List 2:\n");
    for(int i=0; i<12; i++){
        scanf("%s", temp_word);
        add_word(temp_word, &list2);
    }

    // --- 3: Search word (using Contains) ---
    printf("\n--- Search in List 1 ---\n");
    printf("Enter a word to search (type %s to stop): ", SENTINEL);
    scanf("%s", temp_word);
    while(strcmp(temp_word, SENTINEL) != 0){
        if(contains(temp_word, list1)){
            printf("Yes, '%s' is found.\n", temp_word);
        }
        else{
            printf("No, '%s' is NOT found.\n", temp_word);
        }
        printf("Next word: ");
        scanf("%s", temp_word);
    }

    // --- 4: Compare two lists ---
    printf("\n--- Comparing Lists ---\n");
    if(equal_lists(list1, list2)){
        printf("Result: The two lists are identical.\n");
    }
    else{
        printf("Result: The two lists are different.\n");
    }

    // --- 5: Display two lists ---
    printf("\nDisplaying List 1:");
    display_word_list(list1);

    printf("\nDisplaying List 2:");
    display_word_list(list2);

    return 0;
}