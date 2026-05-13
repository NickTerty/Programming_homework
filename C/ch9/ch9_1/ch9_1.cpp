#include<stdio.h>
#define ROW 5
#define COLUMN 5

int blob_check(int grid[ROW][COLUMN], int x, int y){
    
    // Basic Step: Outside?
    if(x < 0 || x >= ROW || y < 0 || y >= COLUMN){
        return 0;
    }   

    // Basic Step: Null or not?
    if(grid[x][y] == 0){
        return 0;
    }

    // Recursive Step
    grid[x][y] = 0;

    int count = 1;
    count += blob_check(grid, x - 1, y);     // top
    count += blob_check(grid, x + 1, y);     // down
    count += blob_check(grid, x, y - 1);     // left
    count += blob_check(grid, x, y + 1);     // right
    count += blob_check(grid, x - 1, y - 1); // left-top
    count += blob_check(grid, x - 1, y + 1); // right-top
    count += blob_check(grid, x + 1, y - 1); // left-down
    count += blob_check(grid, x + 1, y + 1); // right-down

    return count;
}

int main(void){
    // Initialization
    int grid[ROW][COLUMN] = {
        {1, 1, 0, 0, 0}, // Row 0
        {0, 1, 1, 0, 0}, // Row 1
        {0, 0, 1, 0, 1}, // Row 2
        {1, 0, 0, 0, 1}, // Row 3
        {0, 1, 0, 1, 1}  // Row 4
    };

    printf("Counting Blobs...\n\n");

    int blobs = 0;

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            if(blob_check(grid, i, j)){
                blobs++;
            }
        }
    }

    printf("There are(is) %d blob(s) in the grid.\n", blobs);

    return 0;
    
}