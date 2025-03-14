#include <iostream>
#include <algorithm>
using namespace std;
const int MAXLEN = 100010;

int n;
struct Range {
    int l,r;
    bool operator < (const Range &W) const {
        return r < W.r;
    }
}range[MAXLEN];

int main() {
    cin >> n;
    for (int i = 0; i<n; i++) {
        int l,r;
        cin >> l >> r;
        range[i] = {l,r};
    }
    
    sort(range,range+n);
    
    int res = 0;
    int ed = -2e9;
    for (int i = 0; i<n; i++) {
        if (ed < range[i].l) {
            res ++;
            ed = range[i].r;
        }
    }
    cout << res;
}