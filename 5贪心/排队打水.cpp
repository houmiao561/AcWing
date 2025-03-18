#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXLEN = 100010;


long long n;
long long arr[MAXLEN];
long long res = 0;
priority_queue<int, vector<int>, greater<int>> heap;

int main() {
    cin >> n;
    for (int i = 1; i<=n; i++) {
        cin >> arr[i];
        heap.push(arr[i]);
    }
    
    while(heap.size() > 1) {
        int a = heap.top(); heap.pop();
        res += a * heap.size();
    }
    
    cout << res;
}