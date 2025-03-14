#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int* heapArr;
    int size;
} Heap;

int popHeapNum;

Heap* CreatHeap( int numbers );
Heap* BuildHeap ( Heap* head, int arr[] );
void SwapArrayInt(int *a, int *b);
void IntDown( Heap* head, int index );
Heap* PopTop( Heap* head );
void IntUp( Heap* head, int index );

int main() {
    int arrNeedSort[] = {4,2,3,1};
    /*
        4
       2  3
     1   
    第一次调整后
        2
      1   3
    4
    第二次调整后
         1
      2   3
    4   
    */
    Heap* head = CreatHeap(5);
    head = BuildHeap( head, arrNeedSort );
    head = PopTop( head );
    // printf("popHeapNum = %d",popHeapNum);
    // printf("\n取出最顶上一个元素没问题\n就差重新将root坠到最下面这一步了");
    // printf("TEST =  %d\n",head->heapArr[0]);
    // printf("TEST =  %d\n",head->heapArr[1]);
    // printf("TEST =  %d\n",head->heapArr[2]);
    // printf("TEST =  %d\n",head->heapArr[3]);
    // printf("TEST =  %d\n",head->heapArr[4]);
    return 0;
}

Heap* CreatHeap( int numbers ) {
    Heap* head = ( Heap* ) malloc ( sizeof(Heap) );
    head->heapArr = ( int* ) malloc ( sizeof( int ) * numbers );
    head->size = numbers;
    return head;
}

Heap* BuildHeap ( Heap* head, int arr[] ) {
    for( int i = 0; i < head->size; i++ ) {
        head->heapArr[i+1] = arr[i];
        // 没问题，并且在 head->heapArr[]数组中 空出了0号位置
        // 调整 head->heapArr[i+1] 这个新来的数据在 数组 中的位置
        IntDown( head, i+1 );
    }
    // printf("TESTHEAD =  %d\n",head->heapArr[0]);
    // printf("TESTarr =  %d\n",head->heapArr[1]);
    // printf("TESTarr =  %d\n",head->heapArr[2]);
    // printf("TESTarr =  %d\n",head->heapArr[3]);
    // printf("TESTarr =  %d\n",head->heapArr[4]);
    return head;
}

void IntDown( Heap* head, int index ) {
    int temp = index;
    // 满足调整的要求就进来
    if ( head->heapArr[index] < head->heapArr[index/2] && index < head->size ) { 
        // 要一直溯源到最上面
        while ( head->heapArr[temp] < head->heapArr[temp/2] ) {
            SwapArrayInt( &head->heapArr[temp], &head->heapArr[temp/2] );
            temp = temp/2;
        }
    }
}

void SwapArrayInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void IntUp( Heap* head, int index ){
    int temp = index;

    while ( head->heapArr[temp] > head->heapArr[temp*2] || 
    head->heapArr[temp] > head->heapArr[temp*2+1] ) {
        if ( head->heapArr[temp*2] < head->heapArr[temp*2+1] ) { // 左小于右 和左换
            SwapArrayInt( &head->heapArr[temp], &head->heapArr[temp*2] );
            temp = temp * 2;
        } else { // 左大于右 和右换
            if ( head->heapArr[temp*2+1]!= 0) SwapArrayInt( &head->heapArr[temp], &head->heapArr[temp*2+1] );
            temp = temp * 2 + 1;
        }
    }  
}

Heap* PopTop( Heap* head ) {
    popHeapNum = head->heapArr[1]; // 0号位是头节点
    SwapArrayInt( &head->heapArr[1], &head->heapArr[head->size - 1]);
    head->size --;
    head->heapArr = (int*) realloc ( head->heapArr, sizeof(int) * head->size);
    IntUp(head, 1);
    printf("Swap = %d\n",head->heapArr[0]);
    printf("Swap = %d\n",head->heapArr[1]);
    printf("Swap = %d\n",head->heapArr[2]);
    printf("Swap = %d\n",head->heapArr[3]);
    return head;
}