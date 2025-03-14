#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int value;
    struct Node* next;
} Node ;

Node* HeadInsert ( Node* head, int num );
Node* Delete ( Node* head, int k );
Node* Insert ( Node* head, int k, int num);

int main() {
    Node* head = NULL; 
    // 没有头节点，只有头指针，所以啥都没有的时候是野指针
    
    head = HeadInsert(head,3);
    head = HeadInsert(head,4);
    head = HeadInsert(head,5); // 5->4->3
    //printf("head.value = %d\n",head->next->next->value);
    //head = Delete( head, 2 );
    //head = Delete( head, 1 );
    head = Insert(head,9,2);
    printf("head.value = %d\n",head->next->next->value);

    // head = HeadInsert(head,9);
    // head = Insert(head, 1, 1);
    // head = Delete(head, 1);
    // head = Delete(head, 1);
    // head = HeadInsert(head, 6);
    // head = Insert(head, 3, 6);
    // head = Insert(head, 4, 5);
    // head = Insert(head, 4, 5);
    // head = Insert(head, 3, 4);
    // head = Delete(head, 6);
    // printf("head.value = %d\n",head->value);

    return 0;
}

Node* HeadInsert ( Node* head, int num ) {
    Node* insertNode = (Node*) malloc (sizeof(Node));
    insertNode->next = head;
    insertNode->value = num;
    return insertNode;
}

Node* Delete ( Node* head, int k ){
    if ( k == 1 ) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    Node* tempNext = head->next;

    for ( int i = 0; i < k-2; i++ ) {
        tempNext = tempNext->next;
        temp = temp->next;
    }
    temp->next = tempNext->next;
    free(tempNext);
    return head;
}


Node* Insert ( Node* head,int k, int num) {
    if ( k == 1 ) {
        Node* insertNode = (Node*) malloc (sizeof(Node));
        insertNode->next = head;
        insertNode->value = num;
        return insertNode;
    }

    Node* temp = head;
    Node* tempNext = head->next;

    for ( int i = 0; i < k-2; i++ ) {
        tempNext = tempNext->next;
        temp = temp->next;
    }
    Node* insertNode = (Node*) malloc (sizeof(Node));
    insertNode->value = num;
    temp->next = insertNode;
    insertNode->next = tempNext;
    return head;
}



    


