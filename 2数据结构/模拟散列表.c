#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN 16
int hashARR[MAXLEN];

void InitHash();
void InsertValToHash( int num );
void CrushInsert ( int num );
bool QueryNumber ( int num );


int main() {
    InitHash();
    InsertValToHash(3);
    InsertValToHash(9);
    InsertValToHash(3);

    bool TEST = QueryNumber(8);
    if ( TEST ) {
        printf("QueryNumber存在\n");
    } else {
        printf("QueryNumber不存在\n");
    }

    for ( int i = 0; i < MAXLEN; i++ ) {
        printf("%d ",hashARR[i]);
    }
    return 0;
}

void InitHash() {
    for ( int i = 0; i < MAXLEN; i++ ) {
        hashARR[i] = 0;
    }
}

void InsertValToHash( int num ) {
    // num%13 是 i
    if ( hashARR[num%13] == 0 ) {
        hashARR[num%13] = num;
        return;
    }
    CrushInsert(num);
}

void CrushInsert ( int num ) {
    int temp = num%13;
    while ( hashARR[temp] != 0 && temp < MAXLEN ) { 
        temp ++;
    }
    if ( temp < MAXLEN ) {
        hashARR[temp] = num;
    } else {
        printf("hash塞满了");
    }
}

bool QueryNumber ( int num ) {
    int temp = num%13;
    while ( hashARR[temp] != 0 && temp < MAXLEN ) { 
        if ( hashARR[temp] == num ) return true;
        temp ++;
    }
    return false;
}