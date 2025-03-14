#include <iostream>
using namespace std;

const int MAXLEN = 510, INF = 1e9;

int n;
int a[MAXLEN][MAXLEN];
int f[MAXLEN][MAXLEN];
int final = -INF;

int main() {

    // 初始化
    cin >> n;
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=i; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=n; j++) {
            f[i][j] = -INF;
        }
    }
    f[1][1] = a[1][1];
    // 初始化结束
    
    // 核心代码
    for(int i = 2; i<=n; i++){
        for(int j = 1; j<=i; j++) {
            f[i][j] = max(f[i-1][j-1] + a[i][j], f[i-1][j] + a[i][j]);
        }
    }
    // 核心代码结束
    
    // 遍历最后一行得到答案
    for(int i = 1; i<=n; i++) {
        if( f[n][i]>=final ) final = f[n][i];
    }
    cout << final;
    
    return 0;
}