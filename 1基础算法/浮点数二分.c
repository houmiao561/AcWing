/*
    题干是判断浮点数，这样严格二分就可以了，不需要判定上下取整的问题
*/

#include <stdio.h>
#include <stdlib.h>

void TwoPart( float arr[], int right, int n, float x );
// r是右边，n是总个数，x是要求的数

int main() {
    float arr[] = { 1.0, 2.2, 3.3, 3.4, 4.5, 4.6, 4.6, 6.7};
    //              0    1    2    3    4    5    6    7
    TwoPart(arr,7,8,2.2);
    return 0;
}

void TwoPart( float arr[], int right, int n, float x ) {

    // 左边界
    int l1 = 0, r1 = right;
    while ( l1 < r1 ) {
        int mid = (l1+r1)/2;
        if ( arr[mid] >= x ) {
            r1 = mid;
        } else {
            l1 = mid + 1;
        }
    }
    if (arr[l1] == x) {
        printf("left = %d\n",l1);
    } else {
        printf("left = -1\n");
    }

    // 右边界
    int l2 = 0, r2 = right;
    while ( l2 < r2 ) {
        int mid = (l2+r2+1)/2;
        if ( arr[mid] <= x ) {
            l2 = mid;
        } else {
            r2 = mid - 1;
        }
    }
    if (arr[l2] == x) {
        printf("right = %d\n",l2);
    } else {
        printf("right = -1");
    } 

    return;
}