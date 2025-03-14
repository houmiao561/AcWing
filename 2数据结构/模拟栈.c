#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* Push( Node* head, int num );
Node* Pop( Node* head );
bool isEmpty( Node* head );
int Query( Node* head );

int main() {
    // 新建一个模拟栈，使用头节点，头节点 -> 栈顶 -> 栈底
    //                         head
    Node* head = (Node*) malloc ( sizeof(Node) );
    head->value = 0;
    head->next = NULL;

    // PUSH
    head = Push(head,1);
    head = Push(head,2);
    head = Push(head,3);
    printf("PUSH_TEST value = %d\n",head->next->value);

    // POP
    head = Pop(head);
    // head = Pop(head);
    // head = Pop(head);
    // printf("PUSH_TEST value = %d\n",head->next->value);

    if ( !isEmpty(head) ) {
        printf("这个栈不是空的\n");
    } else {
        printf("栈空\n");
    }

    printf("QueryTEST = %d", Query(head));

    return 0;
}

Node* Push( Node* head, int num ) {
    Node* temp = (Node*) malloc ( sizeof(Node) );
    temp->value = num;
    if ( head->next != NULL ) temp->next = head->next;
    head->next = temp;
    return head;
}

Node* Pop( Node* head ) {
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

bool isEmpty( Node* head ) { // 不为空的情况下返回false
    if ( head->next != NULL ) {
        return false;
    }
    return true;
}

int Query( Node* head ) {
    return head->next->value;
}

