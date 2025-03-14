#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100010;

int n;                // 节点总数
vector<int> adj[N];   // 邻接表存储树结构
int ans = N;          // 存储最终结果，初始化为较大的值
int itsize[N];        // 存储每个节点的子树大小

// 返回以u为根的子树的大小，并计算删除u后的最大连通块数
int dfs(int u, int father) {
    itsize[u] = 1;      // 当前节点自身计数为1
    int temp = 0;       // 记录u的子节点中最大的子树大小
    
    for (int v : adj[u]) {
        if (v == father) continue;  // 跳过父节点
        int s = dfs(v, u);          // 递归处理子节点v
        itsize[u] += s;             // 累加子树的节点数
        temp = max(temp, s);        // 更新最大子树大小
    }
    
    // 计算父节点方向的连通块大小
    int parent_part = n - itsize[u];
    // 更新全局最小值
    ans = min(ans, max(temp, parent_part));
    return itsize[u];
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    // 添加以下代码查看邻接表内容
    // cout << "===== 邻接表内容 =====" << endl;
    // for (int u = 1; u <= n; ++u) {
    //     cout << "节点 " << u << " 的邻居: ";
    //     for (int v : adj[u]) {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "======================" << endl;
    // cout << adj[1] << endl;
    
    dfs(1, -1); // 从任意节点开始DFS，这里选择节点1作为起始点

    cout << ans << endl;
    
    return 0;
}