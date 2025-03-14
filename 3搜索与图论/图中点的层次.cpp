#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXLEN = 100010;

int n,m;
int answer;

vector<vector<int>> putAdj(MAXLEN); // 二维数组，
vector<int> dist(MAXLEN,-1);
queue<int> que; // node编号的队列


int main() {
    cin >> n >> m;
    for (int i = 0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        putAdj[a].push_back(b);
    }
    
    // bfs
    dist[1] = 0; // 1距离自己0
    que.push(1);
    
     // BFS遍历
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        
        // 对每一个u的成员遍历
        for (int i = 0; i < putAdj[u].size(); i++) {
            int v = putAdj[u][i];  // 获取第i个邻居
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                que.push(v);
            }
        }
    }

    cout << dist[n] << endl;
    
    return 0;
}