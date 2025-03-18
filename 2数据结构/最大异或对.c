#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    return 0;
}


// int x;
// int y;
// 异或: x^y
// 直接暴力循环了
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXLEN = 100010;

int n;
int arr[MAXLEN];
int res = 0;

int main() {
    cin >> n;
    for ( int i = 0; i<n; i++ ) cin >> arr[i];
    
    for ( int i = 0; i<n; i++ ) {
        for ( int j = 0; j<n; j++ ) {
            res = max( res, arr[i] ^ arr[j] );
        }
    }
    cout << res;
}