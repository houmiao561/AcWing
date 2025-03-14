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


// C++
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXLEN = 100010;
int n,m;
int arr[MAXLEN];
int s[MAXLEN];

int main() {
    cin >> n >> m;
    for (int i = 1; i<=n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    for (int i = 1; i<=n; i++) {
        s[i] = s[i-1] + arr[i];
    }
    
    for (int i = 1; i<=m; i++) {
        int l,r;
        int final = 0;
        cin >> l >> r;
        final = s[r] - s[l-1];
        cout << final << endl;
    }
}

