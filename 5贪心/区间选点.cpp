#include <iostream>
#include <algorithm>
using namespace std;
const int MAXLEN = 100010;
int n;

struct Range {
    int l, r;
    bool operator < (const Range &other) const {
        return r < other.r;
    }
}range[MAXLEN];

int main() {
    cin >> n;
    for(int i = 0; i<n; i++) {
        int l,r;
        cin >> l >> r;
        range[i] = {l,r};
    } // 初始化完成
    
    sort(range,range+n); // 把range[N]完成排序，需要用到里面的operator <
    
    // 开始贪心过程
    int res = 0,ed = -2e9;
    for(int i = 0; i<n; i++) {
        if (range[i].l > ed) {
            res++;
            ed = range[i].r; // 这一步很重要，要随时更新ed为最新的区间的最右端
        }
    }
    
    cout << res;
    return 0;
}