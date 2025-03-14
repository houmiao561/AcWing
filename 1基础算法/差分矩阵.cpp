#include <iostream>
#include <algorithm>
using namespace std;
const int MAXLEN = 1010;

int n,m,q;
int a[MAXLEN][MAXLEN]; // 原矩阵
int b[MAXLEN][MAXLEN]; // 差分矩阵

int main() {
    // 构造a矩阵
    cin >> n >> m >> q;
    for ( int i = 1; i<=n; i++ ) {
        for ( int j = 1; j<=m; j++ ) {
            cin >> a[i][j];
        }
    }
    // 构造差分矩阵
    for ( int i = 1; i<=n; i++ ) {
        for ( int j = 1; j<=m; j++ ) {
            b[i][j] = a[i][j] - a[i][j-1] - a[i-1][j] + a[i-1][j-1];
        }
    }
    // 构造询问输入流，并更改差分矩阵
    for( int i = 0; i<q; i++ ) {
        int x1,y1,x2,y2,c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        b[x1][y1] += c;
        b[x2 + 1][y1] -= c;
        b[x1][y2 + 1] -= c;
        b[x2 + 1][y2 + 1] += c;
    }
    // 求前缀和
    for ( int i = 1; i<=n; i++ ) {
        for ( int j = 1; j<=m; j++ ) {
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    }
    // 打印输出
    for ( int i = 1; i<=n; i++ ) {
        for ( int j = 1; j<=m; j++ ) {
             cout << b[i][j] << " ";
        }
        cout << endl;
    }
    
}
