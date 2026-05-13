#include<stdio.h>
#define QUIT -1

int main(void){
    // input
    int playerNum = 0;
    char batRecord; // H, O, W, S, P
    // calculate
    double batAve = 0;

    printf("Enter the number of player and all bat recording (H, O, W, S, P) from the player (or %d to quit)> ", QUIT);
    scanf("%d", &playerNum);

    while(playerNum != QUIT){
        int totalCount = 0, hitCount = 0; // total(H+O) and hito(H) counting

        scanf("%c", &batRecord);
        printf("Player %d's record: ", playerNum);

        while ( batRecord != '\n' ){
            printf("%c", batRecord);

            if( batRecord == 'H' || batRecord == 'O'){
                totalCount++;
            }
            if( batRecord == 'H' ){
                hitCount++;
            }

            scanf("%c", &batRecord);
        }

        // Evaluate the batting average
        batAve = (double) hitCount / (double) totalCount;

        printf("\nPlayer %d's batting average: %.3lf\n", playerNum, batAve);

        // Calculating the next player's battting record if there is other players.
        printf("Enter the number of player and all bat recording (H, O, W, S, P) from the player (or %d to quit)> ", QUIT);
        scanf("%d", &playerNum);
    }

    return 0;
}