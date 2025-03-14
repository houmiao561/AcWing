#include <iostream>
#include <algorithm>
using namespace std;
const int MAXLEN = 1010;

int n,m,q;
int arr[MAXLEN][MAXLEN];
int s[MAXLEN][MAXLEN];

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            cin >> arr[i][j];
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + arr[i][j]; // 求前缀和
        
        }
    }
    
    // for (int i = 1; i<=n; i++) {
    //     for (int j = 1; j<=m; j++) {
    //         s[i][j] = s[i-1][j-1] + arr[i][j];
    //         // 累加上面的
    //         for (int k = 1; k<i; k++) s[i][j] += arr[k][j];
    //         // 累加左面的
    //         for (int k = 1; k<j; k++) s[i][j] += arr[i][k];
    //     }
    // }
    s[1][1] = arr[1][1];
    
    // for (int i = 1; i<=n; i++) {
    //     for (int j = 1; j<=m; j++) {
    //         cout << s[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    int x1,y1,x2,y2;
    
    while (cin >> x1 >> y1 >> x2 >> y2) { // 2,1  3,4
        int final = 0;
        final = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
        cout << final << endl;
    }
    
    return 0;
    
}