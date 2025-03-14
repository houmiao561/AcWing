#include <iostream>
using namespace std;
const int MAXLEN = 110;

int n,m;
int v[MAXLEN], w[MAXLEN], s[MAXLEN];
int f[MAXLEN][MAXLEN];

int main() {
    cin >> n >> m;
    for (int i = 1; i<=n; i++) cin >> v[i] >> w[i] >> s[i] ;
    
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            for (int k = 0; k<=s[i] && k<=j/v[i]; k++) {
                f[i][j] = max( f[i][j] , f[i-1][j-k*v[i]] + w[i]*k );
            }
        }
    }
    
    cout << f[n][m] << endl;
    return 0;
}