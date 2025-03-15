#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LangArr(int arrTest[],int len);

int main() {
    int testArr[] = {1,2,2,3,5};
    int x = LangArr(testArr,4);
    printf("x = %d",x);
    return 0;
}

int LangArr(int arrTest[],int len){ // len = r
    int tempX = 0;
    for ( int i = 0 ; i < len ; i++ ) {
        int j = i+1;
        while ( j < len && arrTest[j] != arrTest[j+1] && arrTest[j] != arrTest[j-1] ){
            //printf("j = %d\n",j);
            j++;
        }
        printf("i = %d\n",i);
        printf("j = %d\n",j);
        
        if ( tempX < j-i+1 ) {
            printf("j-i = %d\n",j-i+1);
            tempX = j-i+1;
        }
        printf("\n");
    }
    return tempX;
}



// C++
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXLEN = 100010;

int n;
int arr[MAXLEN];
int s[MAXLEN]; // 保存每个数出现了几次
int final = 0;

int main() {
    cin >> n;
    for ( int i = 0; i<n; i++ ) cin >> arr[i];

    for ( int i = 0, j = 0; i<n; i++ ) {
        s[arr[i]]++;
        while ( s[arr[i]] > 1) {
            s[arr[j]]--; // 这里是j！！！
            j++;
        }
        final = max(final,i-j+1);
    }
    cout << final;
}
