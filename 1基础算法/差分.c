#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AddTest(int l, int r, int c,int testArr[]);

int main(){
    int testArr[] = {1,2,2,1,2,1};
    AddTest(1,3,1,testArr);
    AddTest(3,5,1,testArr);
    AddTest(1,6,1,testArr);
    for(int i = 0;i<6;i++){
        printf("%d,",testArr[i]);
    }
    return 0;
}

void AddTest(int l, int r, int c,int testArr[]) {
    for ( int i = l-1; i < r; i++ ){
        testArr[i] += c;
    }
}




// C++
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXLEN = 100010;

int n,m;
int arr[MAXLEN];
int b[MAXLEN];

int main() {
    cin >> n >> m;
    for ( int i = 1; i<=n; i++ ) {
        cin >> arr[i];
        b[i] = arr[i] - arr[i-1];
    }
    
    for ( int i = 1; i<=m; i++ ) {
        int l,r,c;
        cin >> l >> r >> c;
        b[l] += c;
        b[r+1] -= c;
    }
    
    for ( int i = 1; i<=n; i++ ) b[i] += b[i-1];
    
    for ( int i = 1; i<=n; i++ ) cout << b[i] << ' ';
}