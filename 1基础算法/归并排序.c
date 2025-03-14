#include <stdio.h>
#include <stdlib.h>

void MergeSort( int arr[], int l, int r);
void MergeSortInter( int arr[], int l, int r);

int sum = 0;
int sum1 = 0;

int main() {
    int arr[] = {2,5,7,8,3};
    MergeSort( arr, 0, 4);
    for( int i = 0; i<5; i++ ){
        printf("%d,",arr[i]);
    }
    return 0;
}


void MergeSortInter( int arr[], int l, int r){
    sum ++;
    printf(" sum = %d,\n",sum);
    int mergeMid = (l + r)/2;
    int *temArr = (int*) malloc ( sizeof(int) * (r-l+1));
    int i = l;int j = mergeMid + 1; //只作为暂存
    int k = 0;

    // 两个数组都有东西的时候
    while ( i <= mergeMid && j <= r ){
        if (arr[i] < arr[j]){
            temArr[k++] = arr[i++];
        } else {
            temArr[k++] = arr[j++];
        }
    }

    // 只剩一边的时候
    while ( i <= mergeMid ) temArr[k++] = arr[i++];
    while ( j <= r ) temArr[k++] = arr[j++];

    // 保存回去
    for (int t = 0; t < k; t++) {
        arr[l + t] = temArr[t];
    }

    free(temArr);
    return;
}

void MergeSort( int arr[], int l, int r){
    // sum1 ++;
    // printf(" sum1 = %d,\n",sum1);
    if (l >= r) return;
    int mid = (l + r)/2;
    MergeSort( arr, l, mid );
    MergeSort( arr, mid+1, r );
    MergeSortInter( arr, l, r );
    return;
}

/*
    这里的核心思路是
    把最终的单个元素看作为有序arr，这样就不需要构造有序arr了可以直接使用
    然后再merge
*/
