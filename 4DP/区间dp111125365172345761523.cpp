// f[i][j] 表示一个区间[i,j]，然后选这个区级里面的体力最小的放进去

#include <iostream>
using namespace std;
const int MAXLEN = 310;

int n;
int s[MAXLEN];
int f[MAXLEN][MAXLEN];


int main() {
    cin >> n;
    for (int i = 1; i<=n; i++) cin >> s[i];
    for (int i = 1; i<=n; i++) s[i] += s[i-1];
    
    for (int len = 2; len<=n; len++) {
        for (int i = 1; len<=n-i+1; i++) {
            int l = i, r = i+len-1;
            f[l][r] = 1e8;
            for (int k = l; k<r; k++) {
                f[l][r] = min ( f[l][r], f[l][k] + f[k+1][r] + s[r] - s[l-1]);
            }
        }
    }
    
    cout << f[1][n];
    
    return 0;
}

