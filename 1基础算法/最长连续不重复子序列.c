#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LangArr(int arrTest[],int len);

int main() {
    int testArr[] = {1,2,2,3,5};
    int x = LangArr(testArr,4);
    printf("x = %d",x);
    return 0;
}

int LangArr(int arrTest[],int len){ // len = r
    int tempX = 0;
    for ( int i = 0 ; i < len ; i++ ) {
        int j = i+1;
        while ( j < len && arrTest[j] != arrTest[j+1] && arrTest[j] != arrTest[j-1] ){
            //printf("j = %d\n",j);
            j++;
        }
        printf("i = %d\n",i);
        printf("j = %d\n",j);
        
        if ( tempX < j-i+1 ) {
            printf("j-i = %d\n",j-i+1);
            tempX = j-i+1;
        }
        printf("\n");
    }
    return tempX;
}

