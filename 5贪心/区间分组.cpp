#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXLEN = 100010;

int n;
int final = 0, ed = -1e9;
struct Range {
    int l,r;
    bool operator <  (const Range &W) const {
        return l < W.l ;
    }
}range[MAXLEN];

int main() {
    // 初始化
    cin >> n;
    for (int i = 0; i<n; i++) {
        int l,r;
        cin >> range[i].l >> range[i].r;
    }
    sort(range,range + n);
    // 初始化完成
    
    // 初始化了一个heap
    priority_queue <int, vector<int>, greater<int> > heap; 
    // 第一个参数heap中元素的类型，第二个默认，第三个表示小堆，less<int>表示大堆
    
    // 开始贪心
    for(int i = 0; i<n; i++) {
        Range r = range[i];
        if ( heap.empty() || heap.top() >= r.l ) heap.push(r.r);
        else {
            int t = heap.top();
            heap.pop();
            heap.push(r.r);
        }
    }
    
    cout << heap.size();
    
    return 0;
}