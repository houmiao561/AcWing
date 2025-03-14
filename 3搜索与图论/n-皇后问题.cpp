#include <iostream>
using namespace std;
const int MAXLEN = 20;

int n; //待输入棋盘规模
// 横竖斜是不是有Q了  对角线有两条所以要dg和udg
bool raw[MAXLEN] = {false}, cal[MAXLEN], dg[MAXLEN] = {false}, udg[MAXLEN] = {false}; 
char board[MAXLEN][MAXLEN]; // 保存棋盘

void DFS( int u ) {
    if (u==n) {
        for (int i = 0; i<n; i++) puts(board[i]); // 等于是遍历了第一行
        cout << endl; // 换行
        return;
    }
    
    for(int i = 0; i<n; i++) {
        if(!raw[i] && !dg[u+i] && !udg[n-u+i] ) { // 这里udg怕越界所以n-u+i
            board[u][i] = 'Q';
            raw[i] = dg[u+i] = udg[n-u+i] = true; // 占领地盘
            DFS(u+1);
            raw[i] = dg[u+i] = udg[n-u+i] = false; // 恢复现场
            board[u][i] = '.';
        }
    }
}

int main() {
    cin >> n;
    // 棋盘初始化为 '.'
    for( int i = 0; i<n; i++ ) 
        for( int j = 0; j<n; j++ ) 
            board[i][j] = '.';
        
    DFS(0);
    return 0;
}






// 第二种方法
void dfs( int x, int y, int s ) { // x是横坐标，y是纵坐标，u是记录当前一共有多少个皇后
    if ( y == n ) y = 0, x++; // 枚举完第一行，就自动跳到下一行
    if ( x == n ) { // 枚举完最后一行，认为棋盘枚举完了
        if ( s == n ) {
            for (int i = 0; i<n; i++) puts(board[i]); // 等于是遍历了第一行
            cout << endl; // 换行
        }
        return ;
    }

    // 不放皇后
    dfs(x, y+1, s);

    // 放皇后
    if ( !raw[x] && !cal[y] && !dg[x+y] && !udg[x-y+n] ) {
        board[x][y] = 'Q';
        raw[x] = cal[y] = dg[x+y] = udg[x-y+n] = true; // 占领地盘
        dfs(x, y+1, s+1);
        raw[x] = cal[y] = dg[x+y] = udg[x-y+n] = false; // 恢复现场
        board[x][y] = '.';
    }
}