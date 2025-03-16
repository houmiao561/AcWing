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