#include <iostream>
using namespace std;
const int MAXLEN = 100010;

int n;
int arr[MAXLEN];
int final[MAXLEN];

int main() {
    // 初始化建立二叉树
    cin >> n;
    for (int i = 1; i<=n; i++) { // 只是输入次数的循环，具体位置可能无关
        int inputNum; // 保存输入的数字
        
        int temp = 1; // 保存数组下标
        int tempCount = 0;
        
        int faPoint; // 类似于双指针的保存数组下标
        int faPointCount = 0;
        cin >> inputNum;
        
        while (arr[temp] != 0) { // while只是找到应该放的位置
            faPoint = temp; // fa留在这里，但是temp往前先走一步
            faPointCount++;
            if(inputNum > arr[temp]) {
                temp = temp * 2 + 1;
                tempCount++;
            }
            if(inputNum < arr[temp]) {
                temp = temp * 2;
                tempCount++;
            }
        } // 结束循环的时候会少一次，所以要在下面补一次
        arr[temp] = inputNum; // 先确定temp
        
        if (tempCount!= faPointCount) {
            if(inputNum > arr[faPoint]) {
                faPoint = faPoint * 2 + 1;
            } else {
                faPoint = faPoint * 2;
            }
        }
        
        final[inputNum] = arr[faPoint];
        
    } // 建立二叉树没问题
    
    for (int i = 1; i<=n; i++) {
        cout << final[i] << " ";
    }
    
    
    return 0;
}