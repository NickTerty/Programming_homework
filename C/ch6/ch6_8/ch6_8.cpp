#include<stdio.h>
#include<math.h>

double round_money(double num){
    return floor(num * 100 + 0.5) / 100;
}

void charge(double hour, double *avgCharge, double *total){
    if(hour <= 10){
        *total = 7.99;
    }
    else{
        *total = 7.99 + 1.99 * (hour - 10);
    }
    
    *avgCharge = round_money((*total) / hour);
}

int main(void){
    FILE *inp = fopen("usage.txt", "r"); // read a file named usage.txt
    FILE *outp = fopen("charges.txt", "w"); // write the ouput on file named charges.txt

    int month, year;
    fscanf(inp, "%d %d", &month, &year);

    fprintf(outp, "Charges for %d/%d\n", month, year);
    fprintf(outp, "                          Charge\n");
    fprintf(outp, "Customer   Hours used    per hour   Average cost\n");

    int id;
    double hour;

    while(fscanf(inp, "%d %lf", &id, &hour) == 2){
        double total, avg;
        charge(hour, &avg, &total);

        fprintf(outp, "%5d        %5.1f        %5.2f        %5.2f\n", id, hour, total, avg);
    }

    fclose(inp);
    fclose(outp);
    return 0;
}