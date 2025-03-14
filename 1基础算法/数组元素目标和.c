#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TargetAdd( int A[],int lenA, int B[], int lenB, int target );

int main() {
    int A[] = {1,2,4,7};
    int B[] = {3,4,6,8,9};
    TargetAdd(A,4,B,5,4);
    return 0;
}

void TargetAdd( int A[],int lenA, int B[], int lenB, int target ) {
    for( int tempA = 0 ; tempA < lenA ; tempA++ ){
        int tempB = tempA;
        while( tempB < lenB && B[tempB] + A[tempA] != target ) {
            tempB++;
        }
        if ( B[tempB] + A[tempA] == target) {
            printf("tempA = %d\n",tempA + 1);
            printf("tempB = %d\n",tempB + 1);
            return;
        }
    } 
}