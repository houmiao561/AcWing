// #include <iostream>
// #include <cstring>
// using namespace std;
// const int MAXLEN = 100010;
// int arr[MAXLEN];
// string line;
// int ansTemp;
// int ansFinal;

// void dfs(int x, int temp) {
//     if ( arr[x] == 0 ){
//         ansFinal = ansFinal + ansTemp;
//         ansTemp = 0;
//         return;
//     }
    
//     if ( arr[2*x] > temp ) {
//         ansTemp++;
//         dfs(2*x,arr[2*x]);
//     }
//     if ( arr[2*x+1] > temp ) {
//         ansTemp++;
//         dfs(2*x+1,arr[2*x+1]);
//     }
    
//     if ( arr[2*x] < temp ) {
//         dfs(2*x,arr[2*x]);
//     }
//     if ( arr[2*x+1] < temp ) {
//         dfs(2*x+1,arr[2*x+1]);
//     }
    
// }

// int main () {
//     cin >> line;
//     line.push_back(',');
//     int temp = 1;
//     for (int i = 0; i<line.size(); i++) {
//         if (line[i] == '1') {
//             arr[temp] = 1;temp++;
//         }
//         if (line[i] == '2') {
//             arr[temp] = 2;temp++;
//         }
//         if (line[i] == '3') {
//             arr[temp] = 3;temp++;
//         }
//         if (line[i] == '4') {
//             arr[temp] = 4;temp++;
//         }
//         if (line[i] == '5') {
//             arr[temp] = 5;temp++;
//         }
//         if (line[i] == '6') {
//             arr[temp] = 6;temp++;
//         }
//         if (line[i] == '7') {
//             arr[temp] = 7;temp++;
//         }
//         if (line[i] == '8') {
//             arr[temp] = 8;temp++;
//         }
//         if (line[i] == '9') {
//             arr[temp] = 9;temp++;
//         }
//         if (line[i] == 'n')  {
//             arr[temp] = 0;temp++;
//         }
//     }
    
//     dfs(1,arr[1]); // 传入初始节点
//     cout << ansFinal+1;
    
//     return 0;
// }





#include <iostream>
#include <cstring>
using namespace std;
const int MAXLEN = 2000000;

int arr[MAXLEN];
string line;
int res = 1; // 根节点也算关键节点
int tempArr = 1;  // 记录节点位置

void dfs(int x, int temp) { // x 是编号， temp 是当前编号的值
    if (arr[x] == -1 || x > tempArr) return;

    if (arr[x*2] >= temp) {
        res++;
        dfs(x*2, arr[x*2]);
    } else {
        dfs(x*2, arr[x*2]);
    }
    
    if (arr[x*2+1] >= temp) {
        res++;
        dfs(x*2+1, arr[x*2+1]);
    } else {
        dfs(x*2+1, arr[x*2+1]);
    }
    
}

int main () {
    cin >> line;
    line.push_back(',');
    for( int i =0; i<MAXLEN; i++ ) arr[i] = -1;
    
    int val = 0;
    for (int i = 0; i<line.size(); i++) {
        if (isdigit(line[i])) val = val*10 + line[i] - '0';
        else if (line[i] == ',') {
            arr[tempArr] = val;
            tempArr++;
            val = 0;
        } else {
            val = -1;
        }
    } // 输入完成
    
    dfs(1,arr[1]);
    cout << res;
    
    return 0;
}