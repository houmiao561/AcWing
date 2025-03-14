#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void childArr(int x1,int y1,int x2,int y2,int arrTest[][4]);

int main() {
    int arrTest[3][4] = {{1,7,2,4},{3,6,2,8},{2,1,2,3}};
    childArr(2,1,3,4,arrTest);
    return 0;
}

void childArr(int x1,int y1,int x2,int y2,int arrTest[][4]){
    int sum = 0;
    for ( int i = x1 - 1; i < x2; i++ ) {
        for ( int j = y1 - 1; j < y2; j++ ) {
            sum += arrTest[i][j];
        }
    }
    printf("sum = %d",sum);
}