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


// C++
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXLEN = 100010;
int n,m,x;
int a[MAXLEN];
int b[MAXLEN];

int main() {
    cin >> n >> m >> x;
    for ( int i = 0; i<n; i++ ) cin >> a[i];
    for ( int i = 0; i<m; i++ ) cin >> b[i];
    
    int i = 0, j = m-1;
    while( a[i] + b[j] != x ) {
        if ( a[i] + b[j] > x ) j--;
        if ( a[i] + b[j] < x ) i++;
    }
    cout << i << ' ' << j;
    return 0;
}