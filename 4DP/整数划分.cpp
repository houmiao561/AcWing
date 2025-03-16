#include <iostream>
#include <algorithm>
using namespace std;
const int MAXLEN = 1010, mod = 1e9 + 7;
int n;
int f[MAXLEN];

int main() {
    cin >> n;
    f[0] = 1; // n = 5 时认为可以 5 = 0 + 5
    
    for ( int i = 1; i<=n; i++ ) {
        for ( int j = i; j<=n; j++ ) {
            f[j] = (f[j] + f[j - i]) % mod;
        }
    }
    cout << f[n];
}




// f[i][j] 表示前i个整数（1,2…,i）恰好拼成j的方案数
// 可以理解为完全背包问题，i是物品的体积，j是现有背包的大小
// f[i][j] = f[i - 1][j] + f[i][j - i]

#include <iostream>
using namespace std;
const int N = 1e3 + 7, mod = 1e9 + 7;

int n;
int f[N][N];

int main() {
    cin >> n;

    for (int i = 0; i <= n; i ++) {
        f[i][0] = 1; // 容量为0时，前 i 个物品全不选也是一种方案
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= n; j ++) {
            f[i][j] = f[i - 1][j] % mod; // 特殊 f[0][0] = 1
            if (j >= i) f[i][j] = (f[i - 1][j] + f[i][j - i]) % mod;
        }
    }

    cout << f[n][n] << endl;
}