#include <iostream>
using namespace std;

const int MAXLEN = 100010;

int n;
int ans;
int a[MAXLEN];
int f[MAXLEN];

int main() {
    cin >> n;
    for (int i = 1; i<=n; i++) cin >> a[i];
    f[1] = a[1];
    
    for (int i = 2; i<=n; i++) {
        for (int j = 1; j<i; j++) {
            if (a[j] < a[i] && f[i] < f[j] + a[i]) f[i] = a[i] + f[j];
        }
    }
    
    for (long long i = 1; i<=n; i++) ans = max(ans,f[i]);
    cout << ans;
    return 0;
}