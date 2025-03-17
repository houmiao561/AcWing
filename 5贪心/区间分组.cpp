#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXLEN = 100010;

int n;
struct Range {
    int l,r;
    bool operator < (const Range &W) const {
        return l < W.l ? true : false;
    }
} range[MAXLEN];

int arr[MAXLEN]; // 保存max_r // 不需要了
int temp; // 暂存数组长度 // 不需要了

int main() {
    cin >> n;
    for (int i = 0; i<n; i++) cin >> range[i].l >> range[i].r;
    sort(range, range+n);

    /*
    // 分组考虑
    arr[0] = range[0].r;
    temp++;
    for ( int i = 1; i<n; i++ ) {
        int j = 0;
        for ( j; j<temp; j++ ) {
            if ( range[i].l > arr[j] ) {
                arr[j] = range[i].r;
                break;
            } 
        }
        if ( j == temp ) {
            arr[temp] = range[i].r;
            temp++;
        }
    }
    cout << temp;
    
    Time Limit Exceeded了，所以要用heap，用小根堆
    heap的道理是保存各个分组的max_r，堆顶是所有max_r中最小的max_r
    如果堆顶的那个组的max_r小于当前range[i].l，就不需要开新组
    具体操作是直接把这个新来的放到堆顶这个组里面去，然后调整这个组的max_r，heap会自动调整
    先pop再push就可以了呀
    
    如果不存在就开一个新的组
    */
    
    
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
}