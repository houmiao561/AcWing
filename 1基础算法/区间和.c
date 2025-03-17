#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// key  1   3   7
// val  2   6   5

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

void AddSize( int l, int r, Node* head );

int main () {
    Node* head = (Node*) malloc( sizeof (Node) );
    head->key = 0;
    head->value = 0;
    Node* head1 = (Node*) malloc( sizeof (Node) );
    head1->key = 1;
    head1->value = 2;
    Node* head2 = (Node*) malloc( sizeof (Node) );
    head2->key = 3;
    head2->value = 6;
    Node* head3 = (Node*) malloc( sizeof (Node) );
    head3->key = 7;
    head3->value = 5;

    head->next = head1;
    head1->next = head2;
    head2->next = head3;
    head3->next = NULL;

    // AddSize(1,3,head);
    // AddSize(4,6,head);
    AddSize(7,8,head);

    return 0;
}


void AddSize( int l, int r, Node* head ){

    Node* temp = head;
    while ( temp->key < l ) temp = temp->next;
    printf("temp = %d\n",temp->key);

    if ( temp->next != NULL ) {
        Node* tempNext = temp->next;
        while ( tempNext->key < r && tempNext != NULL ) tempNext = tempNext->next;
        printf("tempNext = %d\n",tempNext->key);

        int sum = 0;
        while ( temp != tempNext) {
            printf("tempVAL = %d\n",temp->value);
            sum += temp->value;
            temp = temp->next;
        }

        if (temp == tempNext) sum += temp->value;
        printf("sum = %d",sum);
    } else {
        printf("sum = %d",temp->value);
    }
      
}



// C++
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n,m;
unordered_map<int, int> map; 

int main() {
    cin >> n >> m;
    for ( int i = 0; i<n; i++ ) {
        int x,c;
        cin >> x >> c;
        map[x] += c;
    } // 输入完成
    
    for ( int i = 0; i<m; i++ ) { // 次数
        int l = 0, r = 0, res = 0;
        cin >> l >> r;
        for ( l; l<=r; l++ ) {
            res += map[l];
        }
        cout << res << ' ' << endl;
    }
    
    return 0;
}