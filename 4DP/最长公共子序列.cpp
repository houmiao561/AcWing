[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[p]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]

// 所有由第一个序列前i个字母，和第二个序列前j个字母，构成的公共子序列
// 的最大值
#include <iostream>
using namespace std;
const int MAXLEN = 1010;

int n,m;
char a[MAXLEN],b[MAXLEN];
int f[MAXLEN][MAXLEN];

int main() {
    // 初始化
    cin >> n >> m;
    for (int i = 1; i<=n; i++) cin >> a[i];
    for (int i = 1; i<=m; i++) cin >> b[i];
    // 初始化完成
    
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            
            f[i][j] = max(f[i-1][j],f[i][j-1]); 
            if (a[i] == b[j]) { // 必a[i] == b[j]才能一起往下走
                f[i][j] = max( f[i][j], f[i-1][j-1]+1 );
            }
            
        }
    }
    
    cout << f[n][m] << endl;
    
    return 0;
}
