#include <iostream>
#include <algorithm>
using namespace std;
const int MAXLEN = 100010;
const int INF = 2e9;

int n;
int arr[MAXLEN];
int f[MAXLEN][10]; // 存储最终的权值，其中竖着的是b从0-9

int abs( int x, int y ) {
    if ( x > y ) return x-y;
    return y-x;
}

int main(){
    // 初始化
    cin >> n;
    for (int i = 1; i<=n; i++) cin >> arr[i];
    
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 10; j++)
            f[i][j] = INF;
            
    for (int i = 0; i<10; i++) f[1][i] = abs(arr[1] - i);
    for (int i = 2; i <= n; i ++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)  // 测试b中填哪个
                f[i][j] = min( f[i][j], f[i - 1][k] + abs(arr[i] - j) + (j - k) * (j - k) );
    
    int res = INF;
    for (int i = 0; i < 10; i++)
        res = min(f[n][i], res);
        
    cout << res;
    
    return 0;
}