#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


typedef pair<int,int> PII;
const int N = 110;

int n, m;
int g[N][N];  // 存储网格，0可通行，1为障碍。
int d[N][N];  // 记录每个点到起点的最短距离，初始化为-1表示未访问。
PII q[N*N];  // 存储待处理的 节点，其中q.first是横坐标，q.second是纵坐标

int bfs() {

    int hh = 0, tt = 0; // 模拟指针表示队头和队尾
    q[0] = {0,0}; // 将起点 (0,0) 加入队列

    memset( d, -1, sizeof d ); // 将所有节点的初始距离设为 -1（表示未访问）
    d[0][0] = 0; // 起点到自身的距离为 0

    int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
    // 这是定义向量

    while ( hh <= tt ) { // 队列不空时才继续执行
        // 取出队头节点，hh 指针后移（相当于出队），并且是取出去之后hh再++
        // t.first是横坐标，t.second是纵坐标
        auto t = q[ hh++ ];  
        for ( int i = 0; i < 4; i++ ) { // 取向量
            int x = t.first + dx[i], y = t.second + dy[i]; // 计算新坐标 (x, y)
            if 
            (
                x >= 0 && x < n && y >= 0 && y < m //这是判断是否在边界内 
                && g [x][y] == 0 // 这是判断点是不是可以走的0 
                && d [x][y] == -1
            )
            { // 这是判断这个点还没有走过
                d [x][y] = d[t.first][t.second] + 1;  // 更新新节点的距离
                q[ ++tt ] = {x,y}; // 模拟队列
            }
        }
    }
    
    return d[n-1][m-1];

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++ ){
        for (int j = 0; j < m; j++ ) {
            cin >> g[i][j];
        }
    }
    cout << bfs() << endl;
    return 0;
}

