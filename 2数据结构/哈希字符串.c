#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN 8
char TESTARR[] = "aabbaabb";

char* InitHash( char* arr );
bool QueryArr( int l1, int r1, int l2, int r2, char* head );

int main() {

    char* head = InitHash( head );
    // printf("%s\n",head);
    // printf("head = %c",head[2]);
    // 上面init没问题
    bool test = QueryArr(1,3,4,6,head);
    if(test) {
        printf("==\n");
    } else {
        printf("!=\n");
    }
    
    return 0;
}

char* InitHash( char* arr ) {
    arr = ( char* ) malloc ( sizeof(char) * MAXLEN );
    for( int i = 0; i < MAXLEN; i++ ) {
        arr[i] = TESTARR[i];
    }
    return arr;
}

bool QueryArr( int l1, int r1, int l2, int r2, char* head ) {
    int l1TEMP = l1-1;
    int l2TEMP = l2-1;
    char arr1[ r1-l1+1 ]; // r1 - l1 = 2
    char arr2[ r2-l2+1 ];
    for( int i = 0; i < r1-l1+1; i++ ) {
        arr1[i] = TESTARR[l1TEMP];
        arr2[i] = TESTARR[l2TEMP];
        l1TEMP++;
        l2TEMP++;
    }
    printf("arr1 = %s\n",arr1);
    printf("arr2 = %s\n",arr2);

    for( int i = 0; i < r1-l1+1; i++ ) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}