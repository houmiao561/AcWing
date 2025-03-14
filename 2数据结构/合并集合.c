#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// int main() {
//     return 0;
// }

#include <stdio.h>

#define MAX_SIZE 100

int parent[MAX_SIZE]; // 初始化时候脚标和i一致，
int rank[MAX_SIZE]; // 初始化 高度

void init() {
    for (int i = 0; i < MAX_SIZE; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    // 比较根的序号相等说明是同一个集合，不相等说明不是一个集合才会继续执行下面的程序
    if (rootX != rootY) {   
        if (rank[rootX] < rank[rootY]) {    // rank高度小的放到大的下面
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {    // rank高度小的放到大的下面
            parent[rootY] = rootX;
        } else { // rank高度相等的情况
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) { 
                rank[rootX]++;
            }
        }
    }
}

int main() {
    init();
    unionSets(1, 2);
    unionSets(3, 4);
    unionSets(2, 3);
    
    printf("find(1) = %d\n", find(1));  // 输出根节点（例如4）
    printf("find(1) = %d\n", find(2));  // 输出根节点（例如4）
    return 0;
}