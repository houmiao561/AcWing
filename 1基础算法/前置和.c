#include <stdio.h>

void FrontAdd(int l, int r, int x);

int main() {
    int a[] = {1,2,3,4,5};
    int s[] = {1,5};
    int sum = 0;

    for (int i = 0; i < s[1]; i++) {
        sum += a[i];
    }

    printf("%d",sum);
    
    return 0;
}

