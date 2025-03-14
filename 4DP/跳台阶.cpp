#include <iostream>
using namespace std;
const int MAXLEN = 20;

int n; // 题目规定要走几个台阶
int f[MAXLEN]; // 保存走i个台阶时候的最优解

int main() {
    cin >> n;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i<=n; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    cout << f[n];
    return 0;
}
