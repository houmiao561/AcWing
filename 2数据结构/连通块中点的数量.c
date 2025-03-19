#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN 10

int par[MAXLEN];
char child[MAXLEN] = {'a','b','c','d','e','f','g','h','i','j'};
int rank[MAXLEN];

/*

   i    1   2   3   4
par[i]  1   2   3   4
child   a   b   c   d

child 保存的是实际的圆圈的内容

i是不会变的，i -> par[i]，也就是i的首领就是par[i]

*/



void init() {
    for( int i = 0; i < MAXLEN; i++ ) {
        par[i] = i;
        // rank[i] = 1;
    }
    return;
}

int FindHead( int x ) {
    if ( par[x] != x ) {
        par[x] = FindHead(par[x]);
    }
    return par[x];
}

void Merge( int a, int b ) {
    int rootA = FindHead(a);
    int rootB = FindHead(b);
    if ( rootA == rootB ) return;
    par[rootA] = rootB;
}

bool isSamePart( int a, int b ) {
    if (FindHead(a) == FindHead(b)) return true;
    return false;
}

int main() {
    init();
    Merge(2,3);
    Merge(3,4);
    Merge(7,8);
    printf("child = %c\n",child[9]);
    if ( isSamePart( 2,3 ) ) printf("YES!!\n");
    return 0;
}



// C++
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXLEN = 100010;

int n,m;
int arr[MAXLEN];
int cnt[MAXLEN];

int find(int x) {
    if (arr[x] != x) arr[x] = find(arr[x]);
    return arr[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        arr[i] = i;
        cnt[i] = 1;
    }
    for ( int i = 0; i<m; i++ ) {
        string str;
        int a,b;
        cin >> str;
        if (str == "C") {
            cin >> a >> b;
            a = find(a), b = find(b);
            if (a != b)
            {
                arr[a] = b;
                cnt[b] += cnt[a];
            }
        }
        if (str == "Q1") {
            cin >> a >> b;
            if (find(arr[a]) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        if (str == "Q2") {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
}
