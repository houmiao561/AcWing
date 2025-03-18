#include <iostream>
#include <algorithm>
using namespace std;
const int MAXLEN = 100010;
int n;
int arr[MAXLEN];
int res = 0;

int main() {
    cin >> n;
    for ( int i = 1; i<=n; i++ ) cin >> arr[i];
    sort(arr, arr+n+1);
    
    int location = (1+n)/2;
    for ( int i = 1; i<=n; i++ ) {
        res += abs(arr[location]-arr[i]);
    }
    cout << res;
}

// 仓库选址问题选中位数就行了
