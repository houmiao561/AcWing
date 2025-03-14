#include <iostream>
#include <algorithm>
using namespace std;
const int MAXLEN = 110;

int n,m;
int v[MAXLEN][MAXLEN], w[MAXLEN][MAXLEN];
int s[MAXLEN]; // 记录个数
int f[MAXLEN][MAXLEN];

int main() {
    cin >> n >> m;
    for (int i = 1; i<=n; i++){
        cin >> s[i];
        for (int j = 1; j<=s[i]; j++) {
            cin >> v[i][j] >> w[i][j];
        }
    }
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++) {
            // 初始状态：不选当前组的物品
            f[i][j] = f[i-1][j]; 
            
            // 遍历当前组的所有物品
            for (int k = 1; k <= s[i]; k++) {
                // 如果能放下当前物品，更新最大值
                if (j >= v[i][k]) {
                    f[i][j] = max( f[i][j], f[i-1][j - v[i][k]] + w[i][k] );
                }
            }
        }
    }
    
    cout << f[n][m];
    
    return 0;
}
