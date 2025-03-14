#include <iostream>
using namespace std;

int tempMIN,tempMAX;
int xSmall, xBig;
int yearSmall, monSmall, daySmall;
int yearBig, monBig, dayBig;
int finalAns;

int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool whichIsMAX (int x1, int x2) { // x1 > x2 返回true;
    yearSmall = x1 / 10000;
    monSmall = (x1 / 100) % 100;
    daySmall = x1 % 100;
    
    yearBig = x2 / 10000;
    monBig = (x2 / 100) % 100;
    dayBig = x2 % 100;
    
    if (yearSmall > yearBig) return true;
    if (yearSmall == yearBig && monSmall > monBig) return true;
    if (yearSmall == yearBig && monSmall == monBig && daySmall > dayBig) return true;
    return false;
}

int main() {
    while( cin >> tempMAX >> tempMIN ) {
        // 先判断输入大小
        if ( whichIsMAX(tempMAX,tempMIN) ) {
            xSmall = tempMIN;
            xBig = tempMAX;
        } else {
            xSmall = tempMAX;
            xBig = tempMIN;
        }
        
        // 处理年月分别保存
        yearSmall = xSmall / 10000;
        monSmall = (xSmall / 100) % 100;
        daySmall = xSmall % 100;
        yearBig = xBig / 10000;
        monBig = (xBig / 100) % 100;
        dayBig = xBig % 100;
        
        int temp = 1; // 暂存最终打印的答案
        
        // 先处理day
        if (dayBig < daySmall) {
            dayBig += a[monBig-1];
            monBig -= 1;
        }
        temp += (dayBig - daySmall);
        
        // 再处理mon
        if (monBig < monSmall) {
            for (int i = 0; i<monSmall-monBig; i++) {
                temp += a[monBig];
                monBig ++;
            }
            yearBig -= 1;
        } else {
            for (int i = 0; i<monBig-monSmall; i++) {
                temp += a[monSmall];
                monSmall ++;
            }
        }
        
        // 最后处理year
        if (yearBig>yearSmall) temp += 365*(yearBig-yearSmall);

        // 打印
        cout << temp << endl;
    }
    return 0;
}