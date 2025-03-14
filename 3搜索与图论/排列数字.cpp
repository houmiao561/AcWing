#include <iostream>
using namespace std;

const int MAXLEN = 10;
int n;
int path[MAXLEN];
bool visited[MAXLEN];
// 用 path 数组保存排列，当排列的长度为 n 时，是一种方案，输出。
// 用 visited 数组表示数字是否用过。
// 当 visited[i] 为 true 时：i 已经被用过
// 当 visited[i] 为 false 时，i 没有被用过。
// dfs(i) 表示的含义是：在 path[i] 处填写数字，然后递归的在下一个位置填写数字。
// 回溯：第 i 个位置填写某个数字的所有情况都遍历后， 第 i 个位置填写下一个数字。

void dfs( int u ) {
    if ( u == n ) {
        for (int i = 0; i<n; i++) printf("%d ",path[i]);
        cout << endl;
        return;
    }
    
    for (int i = 0; i<n; i++) {
        if ( !visited[i] ) {
            path[u] = i+1;
            visited[i] = true;
            dfs(u+1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    return 0;
}




// 二叉树常见dfs模板
void dfs(int x) {
    if (找到了) return ;

    dfs(左子树);
    visit;
    dfs(右子树)
}



struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 这里通过path来保存这条路上的节点是谁，所以会在最后pop出来，result中保存了每一个path，所以是二维数组
void dfs(TreeNode* node, vector<int>& path, vector<vector<int>>& result) {
    if (node == nullptr) return;

    path.push_back(node->val);  // 前序遍历：记录当前节点

    // 如果是叶子节点，保存当前路径
    if (node->left == nullptr && node->right == nullptr) {
        result.push_back(path);
    }

    // 递归左右子树
    dfs(node->left, path, result);
    dfs(node->right, path, result);

    path.pop_back();  // 回溯：移除当前节点
    // 因为会弹出，所以只需要一个队列就能保留所有的情况
}



