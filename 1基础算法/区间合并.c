

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MergeArr( int arr1[], int arr2[], int arr3[], int arr4[], int arr5[] );

int main() {
    int arr1[2] = {1,2};
    int arr2[2] = {2,4};
    int arr3[2] = {5,6};
    int arr4[2] = {7,8};
    int arr5[2] = {9,10};

    int x = MergeArr( arr1, arr2, arr3, arr4, arr5 );
    printf("x = %d",x);
    return 0;
}

int MergeArr( int arr1[], int arr2[], int arr3[], int arr4[], int arr5[] ) {
    int sum = 5;
    if ( arr1[1] >= arr2[0] ) sum--;
    if ( arr2[1] >= arr3[0] ) sum--;
    if ( arr3[1] >= arr4[0] ) sum--;
    if ( arr4[1] >= arr5[0] ) sum--;
    return sum;
}



