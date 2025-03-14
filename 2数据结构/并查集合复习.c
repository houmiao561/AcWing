#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN 10

int par[MAXLEN];
int rank[MAXLEN]; // 没有压缩路径 所以没有用到

/*
   i    1   2   3   4
par[i]  1   2   3   4

i是不会变的，i -> par[i]，也就是i的首领就是par[i]
*/

void init() {
    for ( int i = 0; i < MAXLEN; i++ ) {
        par[i] = i;
        rank[i] = 1;
    }
}

int FindHead( int x ) {
    if ( par[x] != x ) {
        par[x] = FindHead(par[x]);
    }
    return par[x];
}

bool isSamePar( int a, int b ) {
    if ( FindHead(a) == FindHead(b) ) return true;
    return false;
}

// 必须找到部落首领链接，小孩要链接必须要找到老大才能完成
// 只不过要考虑两个首领谁链接谁的问题，也就是路径压缩的问题 
void Merge( int a, int b ) {
    int rootA = FindHead(a);
    int rootB = FindHead(b);
    if ( rootA == rootB ) return;

    // 没有优化压缩路径，直接连起来而已
    // par[rootA] = rootB;

    // 来解决路径压缩问题
    if ( rank[rootA] < rank[rootB] ) {
        par[rootA] = rootB;
        rank[rootB]++;
    } else {
        par[rootB] = rootA;
        rank[rootA]++;
    }

}

int main() {
    init();
    Merge(2,3);
    Merge(4,5);
    Merge(3,4);

    Merge(7,8);
    printf("!! = %d\n",FindHead(8));
    if ( isSamePar( 2,9 ) ) printf("YES!!\n");
    return 0;
}

