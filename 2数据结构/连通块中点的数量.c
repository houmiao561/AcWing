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

