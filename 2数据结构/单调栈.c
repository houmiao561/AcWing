#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

// 尾插法
Node* RearInsert ( Node* head, int num );
void TEST( Node* head );

int main() {
    Node* head = (Node*) malloc (sizeof(Node));
    head->next = NULL;
    head->value = 0;
    head = RearInsert(head,4);
    head = RearInsert(head,1);
    head = RearInsert(head,3);
    head = RearInsert(head,2);
    head = RearInsert(head,1);

    // 头节点head=0 -> 4 -> 1 -> 3 -> 2 -> 1 -> NULL
    printf("TEST = %d\n",head->next->value);
    TEST(head);
    return 0;
}

Node* RearInsert ( Node* head, int num ) {
    Node* temp = head;
    while ( temp->next != NULL ) {
        temp = temp->next;
    }
    Node* insertNode = (Node*) malloc (sizeof(Node));
    insertNode->value = num;
    temp->next = insertNode;
    return head;
}

void TEST( Node* head ) {
    Node* temp = head->next;
    while ( temp->next != NULL ) {
        Node* newTemp = temp->next;
        
        while ( newTemp->next != NULL ) {
            if ( temp->value > newTemp->value ) {
                printf("%d\n",newTemp->value);
                break;
            }
            newTemp = newTemp->next;
        }

        if ( temp->value > newTemp->value && newTemp->next == NULL ) {
            printf("%d\n",newTemp->value);
            temp = temp->next;
            continue;
        }

        if ( newTemp->next == NULL ) printf("-1\n");
        temp = temp->next;
    }
    
}


// C++
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
const int MAXLEN = 100010;

int n;
int arr[MAXLEN];
int f[MAXLEN];
int tt; // 指针

int main() {
    cin >> n;
    for (int i = 0; i<n; i++){
        int x ;
        cin >> x;
        while ( tt>0 && f[tt] >= x ) tt--;
        
        if (tt) cout << f[tt] << ' ';
        else cout << -1 << ' ';
        
        f[++tt] = x;
    } 
}
