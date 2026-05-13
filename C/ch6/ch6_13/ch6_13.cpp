#include<stdio.h>
#include<ctype.h>

enum state { start, build_id, identifier, build_num, number, stop };

enum state transition(enum state current, char c) {
    switch (current) {

    case start:
        if (c == ' ') return start;
        if (c == '.') return stop;
        if (isalpha(c)) return build_id;
        if (isdigit(c)) return build_num;
        break;

    case build_id:
        if (isalpha(c) || isdigit(c) || c == '_') return build_id;
        if (c == ' ') return identifier;
        break;

    case build_num:
        if (isdigit(c)) return build_num;
        if (c == ' ') return number;
        break;

    case identifier:
    case number:
        return start;
    }

    return start;
}

int main(void){
    enum state current_state = start;
    char transition_char;

    current_state = start;
    do {
    if (current_state == identifier) {
    printf(" - Identifier\n");
    current_state = start;
    } 
    else if (current_state == number) {
    printf(" - Number\n");
    current_state = start;
    }
    scanf("%c", &transition_char);
    if (transition_char != ' ')
    printf("%c", transition_char);
    current_state = transition(current_state, transition_char);
    } while (current_state != stop);

    return 0;
}