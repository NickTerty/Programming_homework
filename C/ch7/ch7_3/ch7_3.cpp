#include<stdio.h>
#define MAX_N 10
#define MIN_N 3

// returns the actual value of n
int fget_point_mass(int points[][3], int mass[], FILE *input){
    // Scan the file of n
    int n;

    if(fscanf(input, "%d", &n) != 1){
        return -1;
    }
    
    
    // Store the value: points and mass
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            if(fscanf(input, "%d", &points[i][j]) != 1){
                return -1;
            }
        }
        
        if(fscanf(input, "%d", &mass[i]) != 1){
            return -1;
        }
    }

    if(n >= MIN_N && n <= MAX_N){
        return n;
    }
    else{
        return -1;
    }
}

// returns as the function value the center of gravity of the system.
void center_grav(const int points[][3], const int mass[], int n, double cenOfMass[3] /*3 dimension*/){
    if( n > 0){
        int totalMass = 0;

        for(int i = 0; i < n; i++){
            totalMass += mass[i];
        }

        // Component: cenOfMass[0] : x-component, cenOfMass[1] : y-component, cenOfMass[2] : z-component
        for(int i = 0; i < 3; i++){ // Center of Mass
            cenOfMass[i] = 0;
            for(int j = 0; j < n; j++){ //Center of Mass in some component
                cenOfMass[i] += points[j][i] * mass[j];
            }
            // Div the total mass for each component
            cenOfMass[i] = cenOfMass [i] / (double) totalMass;
        }
    }
}

// writes the system to the file with meaningful labels.
void fwrite_point_mass(const int points[][3], const int mass[], int n, const double cenOfMass[3], FILE *output){
    if(n > 0){
        //Display the Location(points)
        fprintf(output, "Location\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++){
                fprintf(output, "%d ", points[i][j]);
            }
            fprintf(output, "\n");
        }

        //Display the mass
        fprintf(output, "\nMass\n");
        for(int i = 0; i < n; i++){
            fprintf(output, "%d\n", mass[i]);
        }

        //Display n
        fprintf(output, "\nn     %d\n\n", n);

        //Display the center of mass
        fprintf(output, "Center of mass\n");
        for(int i = 0; i < 3; i++){
            fprintf(output, "%lf\n", cenOfMass[i]);
        }
    }
    else{
        fprintf(output, "WRONG INPUT OF n!!!");
    }
}

int main(void){
    // input - point (3D), mass and n
    int n;
    int points[MAX_N][3];
    int mass[MAX_N];
    
    // Files
    FILE *inp;
    FILE *outp;

    //output - the center of mass

    double cenOfMass[3];
    
    // open the file - inp in read, outp in write
    inp = fopen("input.txt", "r");
    outp = fopen("output.txt", "w");
    
    while((n = fget_point_mass(points, mass, inp)) != -1 ){
        // Calculate the center of mass
        center_grav(points, mass, n, cenOfMass);

        //Display the value on output file
        fwrite_point_mass(points, mass, n, cenOfMass, outp);
    }
    
    fclose(inp);
    fclose(outp);

    return 0;
}