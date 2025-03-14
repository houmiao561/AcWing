#include <iostream>
using namespace std;

const int MAXLEN = 100010;

// fn += f k * f n-1-k;
// 求和！求和！
// 所以是 += += +=！！！！！

int n;
long long f[MAXLEN];

int main() {
    cin >> n;
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i<=n; i++) {
        for (int k = 0; k<=i-1; k++) {
            f[i] += f[k] * f[i-1-k] ;
        }
    }
    
    cout << f[n];
    return 0;
}
