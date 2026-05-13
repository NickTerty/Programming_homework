#include<stdio.h>
#define NOT_FOUND -1

/* Binary Search pseudocode
bottom = 0;
top = n;
found = 0;
while(bottom < top and !found){
    middle = (top + mid) / 2;
    if(arr[middle] == target)
        found = 0;
        return middle;
    else if(arr[middle] > target)
        top = middle - 1;
    else
        bottom = middle + 1; 
}
*/
int binary_srch(const int arr[], int target, int n){
    int bottom = 0; // Let bottom be the subscript(index) of the initial array element.
    int top = n; // Let top be the subscript of the last array element.
    int found = 0; // Let found be false.

    // Repeat as long as bottom isn’t greater than top and the target has not been found
    while(bottom < top && !found){
        // Let middle be the subscript of the element halfway between bottom and top.
        int middle = (bottom + top) / 2;
        // if the element at middle is the target
        if(arr[middle] == target){
            // Set found to true and index to middle.
            found = 1;
            return middle;
        }
        // else if the element at middle is larger than the target
        else if (arr[middle] > target){
            // Let top be middle − 1.
            top = middle - 1;
        }
        else{
            // Let bottom be middle + 1.
            bottom = middle + 1;
        }
    }

    if(!found){
        return NOT_FOUND;
    }
}
