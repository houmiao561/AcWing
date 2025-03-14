#include <iostream>
using namespace std;
const int MAXLEN = 20;

int n; //待输入棋盘规模
bool raw[MAXLEN] = {false},dg[MAXLEN] = {false},udg[MAXLEN] = {false}; 
char board[MAXLEN][MAXLEN]; 

void DFS( int u ) {
    if (u==n) {
        for (int i = 0; i<n; i++) puts(board[i]); // 等于是遍历了第一行
        puts(""); // 换行
        return;
    }
    
    for(int i = 0; i<n; i++) {
        if(!raw[i] && !dg[u+i] && !udg[n-u+i] ) {
            board[u][i] = 'Q';
            raw[i] = dg[u+i] = udg[n-u+i] = true;
            DFS(u+1);
            raw[i] = dg[u+i] = udg[n-u+i] = false;
            board[u][i] = '.';
        }
    }
}

int main() {
    cin >> n;
    for( int i = 0; i<n; i++ ) {
        for( int j = 0; j<n; j++ ) {
            board[i][j] = '.';
        }
    }
    DFS(0);
    return 0;
}