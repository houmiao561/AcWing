#include <iostream>
using namespace std;
const int MAXLEN = 100010;

// 到达a1，打饭耗时t1, 最大等待时间b1，
// a,t,b

int n;
int timeSum = 1;

int main() {
    cin >> n;
    
    int a1,t1,b1;
    cin >> a1 >> t1 >> b1;
    timeSum = a1;
    cout << timeSum << " ";
    timeSum += t1;
    
    for (int i = 0; i<n-1; i++) {
        int a,t,b;
        cin >> a >> t >> b;
        if (timeSum <= a+b && a < timeSum) { // 能等得起，食堂大妈没时间偷懒
            cout << timeSum << " ";
            timeSum += t;
        } else if (timeSum <= a+b && a > timeSum) { // 食堂大妈有时间偷懒
            cout << a << " ";
            timeSum=a;
        } else {
            cout << -1 << " ";
        }
    }
    
    
    return 0;
}