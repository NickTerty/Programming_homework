#include<stdio.h>
#define MAX_N 100

typedef struct{
    int xx, yy, zz, mm;
    char nickname[10];
}address_t;

void scan_address(address_t *address){
    scanf("%d.%d.%d.%d %s", &address->xx, &address->yy, &address->zz, &address->mm, address->nickname);
}

void print_address(address_t address){
    printf("%d.%d.%d.%d %s\n", address.xx, address.yy, address.zz, address.mm, address.nickname);
}

int local_address(address_t address1, address_t address2){
    if(address1.xx == address2.xx && address1.yy == address2.yy){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void){
    address_t address[MAX_N];

    printf("Enter of internet addresses(xx.yy.zz.mm nickname):\n");
    int n = 0;
    while(n < MAX_N){
        scan_address(&address[n]);

        if(address[n].xx == 0 && address[n].yy == 0 && address[n].zz == 0 & address[n].mm == 0){
            break;
        }

        n++;
    }

    printf("\nFull list of addresses:\n");
    for(int i = 0; i < n; i++){
        print_address(address[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n;j++){
            if(local_address(address[i], address[j]) == 1){
                printf("Machines %s and %s are on the same local network.\n", address[i].nickname, address[j].nickname);
            }
        }
    }

    return 0;
}