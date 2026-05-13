#include<stdio.h>

int mazeSolve(char maze[8][8], int x, int y){
    /*
    Part 1: Basic Step
    */

    // determine it is in range or not
    if(x < 0 || x > 7 || y < 0 || y > 7){
        return 0;
    }

    // determine it is 'X'(wall) or '*'(walked)
    if(maze[x][y] == 'X' || maze[x][y] == '*'){
        return 0;
    }

    // determine it is maze[7][7] or not
    if( x == 7 && y == 7){
        printf("Path: (%d, %d) ", x, y); // print to get the location
        return 1;
    }

    /*
    Part 2: Recursive Step
    */

    maze[x][y] = '*';
    if(mazeSolve(maze, x - 1, y) == 1){
        printf("<- (%d, %d) ", x, y);
        return 1;
    }
    if(mazeSolve(maze, x + 1, y) == 1){
        printf("<- (%d, %d) ", x, y);
        return 1;
    }
    if(mazeSolve(maze, x, y - 1) == 1){
        printf("<- (%d, %d) ", x, y);
        return 1;
    }
    if(mazeSolve(maze, x, y + 1) == 1){
        printf("<- (%d, %d) ", x, y);
        return 1;
    }

    /*
    Part 3: Backtracking
    */
    return 0;
}

int main(void){
    char maze[8][8] = {
        {'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X'},
        {'X', ' ', 'X', 'X', ' ', 'X', 'X', 'X'},
        {'X', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'X', ' ', ' ', 'X', 'X', ' ', 'X', 'X'},
        {'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X'},
        {' ', 'X', 'X', 'X', ' ', 'X', ' ', ' '},
        {' ', 'X', ' ', ' ', ' ', 'X', ' ', ' '}
    };

    int x = 0, y = 1;

    if (mazeSolve(maze, x, y) == 0) {
        printf("No path found.\n");
    }

    return 0;
}