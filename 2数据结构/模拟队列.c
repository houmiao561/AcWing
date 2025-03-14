#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

Node* RearPush ( Node* rear, int num );
Node* HeadPop ( Node* head );
bool isEmpty ( Node* head, Node* rear );
int Query ( Node* head );


int main() {
    Node* head = (Node*) malloc (sizeof(Node));
    Node* rear = (Node*) malloc (sizeof(Node));

    head->value = 0;
    rear->value = 0;
    head->next = rear;
    rear->prev = head;
    // 头节点和尾节点，头节点指向尾节点
    
    rear = RearPush(rear,1);
    rear = RearPush(rear,2);
    rear = RearPush(rear,3);
    head = HeadPop(head);
    head = HeadPop(head);
    printf("TEST = %d\n",head->next->value);
    if ( !isEmpty( head, rear ) ) printf("???\n");
    printf("TEST!!! = %d\n",Query(head));
    return 0;
}

Node* RearPush ( Node* rear, int num ) {
    Node* temp = (Node*) malloc (sizeof(Node));
    temp->value = num;
    // add
    temp->next = rear;
    temp->prev = rear->prev;
    rear->prev->next = temp;
    rear->prev = temp;
    return rear;
}


Node* HeadPop ( Node* head ) {
    Node* temp = head->next; // free temp
    // del
    temp->next->prev = head;
    head->next = temp->next;
    free(temp);
    return head;
}

bool isEmpty ( Node* head, Node* rear ) { // 空的返回 false
    if ( head->next == rear ) return true;
    return false;
}

int Query ( Node* head ) {
    return head->next->value;
}
