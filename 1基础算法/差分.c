#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AddTest(int l, int r, int c,int testArr[]);

int main(){
    int testArr[] = {1,2,2,1,2,1};
    AddTest(1,3,1,testArr);
    AddTest(3,5,1,testArr);
    AddTest(1,6,1,testArr);
    for(int i = 0;i<6;i++){
        printf("%d,",testArr[i]);
    }
    return 0;
}

void AddTest(int l, int r, int c,int testArr[]) {
    for ( int i = l-1; i < r; i++ ){
        testArr[i] += c;
    }
}