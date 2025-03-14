#include <iostream>
using namespace std;
const int MAXLEN = 1010;

int n,m;
char a[MAXLEN],b[MAXLEN];
int f[MAXLEN][MAXLEN]; // a[1-i] -> b[1-j] 的所有方式中的最小值

int main() {
    
    cin >> n;
    for (int i = 1; i<=n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1; i<=m; i++) cin >> b[i];
    
    for (int i = 0; i<=m; i++) f[0][i] = i;
    for (int i = 0; i<=n; i++) f[i][0] = i;
    

    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            f[i][j] = min(f[i-1][j]+1,f[i][j-1]+1); // 暂存更新的最小值
            if (a[i] == b[j]) f[i][j] = min(f[i][j],f[i-1][j-1]+0);
            if (a[i] != b[j]) f[i][j] = min(f[i][j],f[i-1][j-1]+1);
        }
    }
    
    cout << f[n][m];
    
    return 0;
}