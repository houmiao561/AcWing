// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// const int MAXLEN = 100010;
// int n,m; // n个点，m个边
// vector<int> adj[MAXLEN]; // 记录边的情况
// int nodeInPut[MAXLEN]; // 记录每个边的入度，只有入度=0的情况下才可以放入队列
// bool visited[MAXLEN] = {}; // 是否入队过
// queue<int> que; // 层序遍历的队列


// void tuopu() {
//     while(!que.empty()) {
//         int current = que.front();
//         // cout << current << " ";
//         for(int i = 0; i<adj[current].size(); i++) {
            
//             int nextNode = adj[current][i]; // 节点号
//             nodeInPut[nextNode] --;
            
//             // 入度减为0且未访问过
//             if (nodeInPut[nextNode] == 0 && !visited[nextNode]) {
//                 que.push(nextNode);
//                 visited[nextNode] = true;
//             }
//         }
//         // cout << adj[3].size() << "zheshiadj3333" << endl;
//         cout << que.front() << " ";
//         que.pop();
//     }
// }

// int main() {
//     cin >> n >> m;
    
//     for (int i = 0; i < m; i++) {
//         int a, b;
//         cin >> a >> b;
        
//         // 检查边是否已存在
//         bool exists = false;
//         for (int j = 0; j < adj[a].size(); j++) {  // 正确遍历方式
//             if (adj[a][j] == b) {
//                 exists = true;
//                 break;
//             }
//         }
        
//         // 不存在时才添加
//         if (!exists) {
//             adj[a].push_back(b);
//             nodeInPut[b]++;
//         }
//     }
    
//     for(int i = 0; i<n; i++) {
//         if (nodeInPut[i] == 0 && !visited[i]){
//             que.push(i+1);
//             visited[i] = true;
//             // break;
//         } 
//     }
    
//     tuopu();
    
//     return 0;
// }










#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXLEN = 100010;
int n,m;
vector<int> adj[MAXLEN];
int nodeInPut[MAXLEN];
bool visited[MAXLEN] = {};
queue<int> que;
queue<int> finalNum;

void tuopu() {
    while(!que.empty()) {
        int current = que.front();
        // 修改了循环范围和索引方式
        for(int i = 0; i < adj[current].size(); i++) {  // 索引从0开始
            int nextNode = adj[current][i];
            nodeInPut[nextNode]--;
            
            if (nodeInPut[nextNode] == 0 && !visited[nextNode]) {
                que.push(nextNode);
                visited[nextNode] = true;
            }
        }
        finalNum.push(que.front());
        que.pop();
    }
    
    if (finalNum.size() != n) {
        cout << -1;
        return;
    }
    
    while (!finalNum.empty()) {
        cout << finalNum.front() << ' ';
        finalNum.pop();
    }
    
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        bool exists = false;
        for (int j = 0; j < adj[a].size(); j++) {
            if (adj[a][j] == b) {
                exists = true;
                break;
            }
        }
        
        if (!exists) {
            adj[a].push_back(b);
            nodeInPut[b]++;
        }
    }
    
    for(int i = 1; i <= n; i++) {  // 保持i的起始为1不变
        if (nodeInPut[i] == 0){
            que.push(i);
            visited[i] = true;
        } 
    }
    
    tuopu();
    
    return 0;
}