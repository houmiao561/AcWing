#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Heap {
    int *array;
    int size;
    int capacity;
} Heap;

Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->array = (int*)malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(Heap* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->array[index] >= heap->array[parent]) {
            break;
        }
        swap(&heap->array[index], &heap->array[parent]);
        index = parent;
    }
}

void heapifyDown(Heap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left] < heap->array[smallest]) {
        smallest = left;
    }
    if (right < heap->size && heap->array[right] < heap->array[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap->array[index], &heap->array[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insert(Heap* heap, int value) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->array = (int*)realloc(heap->array, sizeof(int) * heap->capacity);
    }
    heap->array[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

int extractMin(Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    int min = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return min;
}

void printHeap(Heap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

int main() {
    Heap* heap = createHeap(3);
    
    insert(heap, 4);
    insert(heap, 1);
    insert(heap, 3);
    insert(heap, 2);
    printHeap(heap); // 应输出 1 2 3 4 或其他符合小根堆结构的排列
    
    printf("Extracted min: %d\n", extractMin(heap)); // 1
    printf("Extracted min: %d\n", extractMin(heap)); // 2
    printf("Extracted min: %d\n", extractMin(heap)); // 3
    printf("Extracted min: %d\n", extractMin(heap)); // 4
    
    // 释放内存
    free(heap->array);
    free(heap);

    return 0;
}