#include <stdio.h>
#include <stdlib.h>
void QSort(int arr[], int low, int high);
int Par(int arr[], int low, int high);

int main() {
    int testArr[] = {2,54,1,6,7,3};
    QSort( testArr, 0, 5 );
    for( int i = 0; i<=5; i++ ){
        printf("%d,",testArr[i]);
    }
    return 0;
}

void QSort( int arr[], int low, int high ) {
    if ( low < high ) {
        int par = Par(arr,low,high);
        Par(arr,low,par-1);
        Par(arr,par+1,high);
    } 
}

int Par( int arr[], int low, int high ) {
    int pivot = arr[high];
    while ( low < high ){
        while( low < high && arr[low] <= pivot ) low++;
        arr[high] = arr[low];
        while ( low < high && arr[high] >= pivot ) high--;
        arr[low] = arr[high];
    }
    arr[high] = pivot;
    return high;
}