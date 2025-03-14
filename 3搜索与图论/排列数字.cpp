#include <iostream>
#include <cstring>
using namespace std;

const int N = 10;
bool used[N]; // 全局数组，标记数字是否被使用
int n; // 输入
int path[N]; // 最终的输出结果暂存位置，在核心循环里是path[u]，也就是深度

void DFS(int u){ // u 表示当前递归处理的位置，具体作用是 ​控制递归的深度
    if(u == n){
        for (int i = 0; i < n; i ++ ) printf("%d ", path[i]);
        printf("\n");
        return;
    }
    
    for (int i = 0; i<n; i++) {
       if (!used[i]) {          // 如果数字 (i+1) 未被使用
            path[u] = i + 1;    // 将数字 (i+1) 填入当前位置
            used[i] = true;     // 标记该数字已被使用
            DFS(u + 1);         // 递归处理下一个位置
            used[i] = false;    // 回溯：恢复该数字为未使用
        }
    }
}

int main() {
    cin >> n;
    DFS(0);
    return 0;
}