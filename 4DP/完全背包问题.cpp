#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAXLEN = 10010;

int n,m; // n个物品，m个背包空间，遍历二维数组f[n][m]
int v[MAXLEN], w[MAXLEN]; // 每种物品有无限个
int f[MAXLEN][MAXLEN]; // DP状态数组
// 含义是下标 0-i之间的物品 任取 放到容量为j的背包里

void select(){
    for (int i = 1; i<=n; i++) {  // 遍历每个物品
        for (int j = 0; j<=m; j++) { // 遍历所有可能的背包容量
            for (int k = 0; k<=j/v[i]; k++) {
                f[i][j] = max(f[i][j], f[i-1][j-k*v[i]]+k*w[i]); // 更新最优解
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    select();
    cout << f[n][m] << endl;
    return 0;
}
