#include <stdio.h>
#include <stdlib.h>

void TwoPart( int arr[], int right, int n, int x );
// r是右边，n是总个数，x是要求的数

/*
    题干是判定一个 有序数组 中，某个数字的起始位置和结束位置
*/

int main() {
    int arr[] = {1,2,3,3,4,4,4,6};
    //           0,1,2,3,4,5,6,7
    TwoPart(arr,7,8,3);
    return 0;
}

void TwoPart( int arr[], int right, int n, int x ) {

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


/*
    这里的核心问题是要搞清楚向上取整还是向下
    以及数组下标问题
*/
