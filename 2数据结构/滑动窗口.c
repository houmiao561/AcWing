#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void SlipWindow( int arr[], int arrLen, int len );

int main() {
    int testArr[] = {1,3,-1,-3,5,3,6,7};

    SlipWindow( testArr, 8, 3 );

    return 0;
}


void SlipWindow( int arr[], int arrLen, int len ) {
    int slipNums = arrLen - len + 1;
    printf("slipNums = %d\n",slipNums);
    for ( int i = 0; i < slipNums; i++ ) {
        int temp = arr[i]; // 暂存最小值
        int tempMax = arr[i]; // 暂存最大值
        for ( int j = 0; j < len; j++) {
            if ( arr[i+j] < temp ) {
                temp = arr[i+j];
            }
            if ( arr[i+j] > tempMax ) {
                tempMax = arr[i+j];
            }
        }
        printf("temp = %d\n",temp);
        printf("tempMax = %d\n",tempMax);
    }
}