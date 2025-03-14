#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAXLEN = 1010;

int n,m;
int v[MAXLEN], w[MAXLEN]; // 每种物品只有一个
int f[MAXLEN][MAXLEN]; // DP状态数组
// 含义是下标 0-i之间的物品 任取 放到容量为j的背包里


void select(){
    for (int i = 1; i<=n; i++) {  // 遍历每个物品
        for (int j = 0; j<=m; j++) { // 遍历所有可能的背包容量
            
            f[i][j] = f[i-1][j]; // 默认情况不带第i个
            if ( j>=v[i] ) { // 如果当前容量能装下第i个物品
                f[i][j] = max(f[i][j], f[i-1][j-v[i]]+w[i]); // 更新最优解
            }
            
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    
    // 暴力得出所有情况，v是总体积
    select();
    cout << f[n][m] << endl;
    
    return 0;
}

/*
假设输入：

n=3, m=4
物品1: v=1, w=15
物品2: v=3, w=20
物品3: v=4, w=30

状态表 f[i][j] 的构建过程：

物品\容量	0	1	2	3	4
0（无物品）	0	0	0	0	0
1（体积1）	0	15	15	15	15
2（体积3）	0	15	15	20	35
3（体积4）	0	15	15	20	35
*/
