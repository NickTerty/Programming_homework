#include<stdio.h>

void hannoiTower(int n, char start, char mid, char final){
    if(n == 1){
        printf("Move disk %d form %c to %c\n", n, start, final);
    }
    else{
        hannoiTower(n - 1, start, final, mid);
        printf("Move disk %d form %c to %c\n", n, start, final);
        hannoiTower(n - 1, mid, start, final);
    }
}

int main(void){
    int n;
    char start = 'A', mid = 'B', final = 'C';

    printf("Enter total disks: ");
    scanf("%d", &n);

    hannoiTower(n, start, mid, final);

    return 0;
}