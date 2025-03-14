#include <iostream>
using namespace std;

const int MAXLEN = 1010;

int n;
int ans;
int a[MAXLEN];
int f[MAXLEN];

int main() {

    // 初始化
    cin >> n;
    for (int i = 1; i<=n; i++) cin >> a[i];
    f[1] = 1;
    // 初始化完成

    // 核心函数
    for (int i = 1; i<=n; i++) {
        f[i] = 1;
        for (int j = 1; j<i; j++) {
            if (a[j]<a[i]) f[i] = max(f[i],f[j]+1);
        }
    }
    
    //比大小输出
    for(int i = 1; i<=n; i++) ans = max(f[i],ans);
    cout << ans;
    
    return 0;
}