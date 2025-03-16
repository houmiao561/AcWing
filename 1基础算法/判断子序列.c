#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TwoB( int x );

int main() {
    int arrTest[] = {1,2,3,4,5};
    TwoB( arrTest[4] );
    return 0;
}

void TwoB( int num ) {
    // 获取 int 的位数（通常为 32 位）
    int bits = sizeof(num) * 8; // bits是位数，在循环中起判断循环条件的作用
    unsigned int unum = (unsigned int)num; // 处理负数（转为无符号数）

    // 从最高位到最低位逐位检查
    for (int i = bits - 1; i >= 0; i--) {
        // >> 的作用是右移二进制一位，&1 的作用是捕捉 未舍弃的 最后一位
        int bit = (unum >> i) & 1;
        printf("%d", bit);
        
        // 每 4 位添加一个空格，提高可读性（可选）
        if (i % 4 == 0 && i != 0) printf(" ");
    }
    printf("\n");
}


#include <iostream>
#include <algorithm>
using namespace std;
const int MAXLEN = 100010;
int n,m;
int a[MAXLEN];
int b[MAXLEN];

int main() {
    cin >> n >> m;
    for ( int i = 0; i<n; i++ ) cin >> a[i];
    for ( int i = 0; i<m; i++ ) cin >> b[i];
    
    int indexA=0, indexB=0;
    while ( indexB<m && indexA<n ) {
        if (a[indexA] == b[indexB]) indexA++;
        indexB++;
    }
    if (indexA == n) cout << "Yes";
    else cout << "No";
}