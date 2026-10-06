#include<stdio.h>
#define PRECINCT 5
#define CANDID_NUM 4

// a function that display the table with appropriate labels for the rows and columns.
void displayTable(const int votes[][CANDID_NUM]){
    printf("Precinct  Candidate A  Candidate B  Candidate C  Candidate D\n");
    for(int i = 0; i < PRECINCT; i++){
        printf("    %d    ", i+1);
        for(int j = 0; j < CANDID_NUM; j++){
            printf("     %d     ", votes[i][j]);
        }
        printf("\n");
    }
}

/*Compute and display the total number of votes 
received by each candidate and the percentage of the total votes cast.*/
// We will write a function for above content
void race(const int votes[][CANDID_NUM], const char candidates[]){
    int total[CANDID_NUM]= {0};
    int sum = 0;
    for(int i = 0; i < CANDID_NUM; i++){
        for(int j = 0; j < PRECINCT; j++){
            total[i] += votes[j][i];
            sum += votes[j][i];
        }
    }

    //percentage
    double percent[CANDID_NUM] = {0};
    for(int i = 0; i < CANDID_NUM; i++){
        percent[i] = total[i] * 100 / (double)sum;
    }
    printf("Total votes and percentage\n");
    printf("               Total    percentage(%%) \n");
    for(int i = 0; i < CANDID_NUM; i++){
        printf("Candidate %c      %d         %.2lf%%\n", candidates[i], total[i], percent[i]);
    }

    // Declearing the winner of mayor’s race or a runoff between the two candidates.
    double highest = percent[0];
    double secHighest = percent[1];
    int winCand = 0, secCand = 1;
    if(secHighest > highest){
        highest = percent[1];
        secHighest = percent[0];
        winCand = 1;
        secCand = 0;
    }
    for(int i = 0; i < CANDID_NUM - 1; i++){
        int temp = percent[i + 1];
        if(temp > highest){
            highest = temp;
            winCand = i + 1;
        }
        else if(temp > secHighest){
            secHighest = percent[i + 1];
            secCand = i + 1;
        }
    }

    if(highest >= 50){
        printf("The winner of mayor’s race is Candidate %c!\n", candidates[winCand]);
    }
    else{
        printf("There is no one received 50%% of the votes.\n", candidates[winCand]);
        printf("We will have a runoff between Candidate %c and Candidate %c.\n", candidates[winCand], candidates[secCand]);
    }
}

int main(void){
    int votes[PRECINCT][CANDID_NUM]={
        {192, 48, 206, 37},
        {147, 90, 312, 21},
        {186, 12, 121, 38},
        {114, 21, 408, 39},
        {267, 13, 382, 29},
    };
    char candidates[CANDID_NUM]={'A', 'B', 'C', 'D'};

    // Display the table with appropriate labels for the rows and columns.
    displayTable(votes);

    // Run first time for haven't changed
    race(votes, candidates);
    
    /*
    Run the program once with the data shown and once with candidate C 
    receiving only 108 votes in Precinct 4.
    */

    votes[3][2] = 108;

    // Run second time for candidate C receiving only 108 votes in Precinct 4
    race(votes, candidates);
    
    return 0;
}