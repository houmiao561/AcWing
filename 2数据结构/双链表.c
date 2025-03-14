#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
}Node;

// 最左侧插入
Node* LeftInsert( Node* head, int nums );
// 最右侧插入
Node* RightInsert( Node* head, int nums );
// 删除第K个插入的
Node* Delete( Node* head, int k );
// 第K个左侧插入
Node* LeftInsert_KKK( Node* head, int k, int num );
// 第K个右侧插入
Node* RightInsert_KKK( Node* head, int k, int num );


int main() {
    Node* leftHead = NULL;
    leftHead = LeftInsert(leftHead,10);
    leftHead = LeftInsert(leftHead,20);
    printf("头节点值: %d\n", leftHead->value);              
    printf("第二个节点值: %d\n", leftHead->next->value); 
    printf("第二个节点的前驱值: %d\n", leftHead->next->prev->value); 
    
    leftHead = RightInsert(leftHead,3);
    printf("第三个节点值: %d\n", leftHead->next->next->value); 
    printf("第三个节点的前驱值: %d\n", leftHead->next->next->prev->value); 
    
    leftHead = Delete(leftHead,2);
    printf("第二个节点值: %d\n", leftHead->next->value); 
    printf("第二个节点的前驱值: %d\n", leftHead->next->prev->value); 
    

    return 0;
}

Node* LeftInsert( Node* head, int nums ) {
    Node* temp = (Node*) malloc (sizeof(Node));
    temp->value = nums;
    temp->prev = NULL;
    temp->next = head;
    if (head != NULL) {
        head->prev = temp;
    }
    return temp;
}

Node* RightInsert( Node* head, int nums ) {
    Node* temp = (Node*) malloc (sizeof(Node));
    temp->value = nums;

    Node* tempFindRight = head;
    while ( tempFindRight->next != NULL ) {
        tempFindRight = tempFindRight->next;
    }
    
    tempFindRight->next = temp;
    temp->prev = tempFindRight;
    return head;
}

Node* Delete( Node* head, int k ) { // 从左往右第k个删除
    if ( k == 1 ) {
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
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
    tempNext->next->prev = temp;
    free(tempNext); // 删除的是tempNext
    return head;
}

Node* LeftInsert_KKK( Node* head, int k, int num ) {
    if ( k == 1 ) {
        head = LeftInsert(head,num);
        return head;
    }

    Node* temp = head;
    Node* tempNext = head->next;
    for ( int i = 0; i < k-2; i++ ) {
        tempNext = tempNext->next;
        temp = temp->next;
    }

    Node* insertNode = ( Node* ) malloc ( sizeof( Node ) );
    insertNode->value = num;
    temp->next = insertNode;
    insertNode->prev = temp;
    insertNode->next = tempNext;
    tempNext->prev = insertNode;
    return head;
}

Node* RightInsert_KKK( Node* head, int k, int num ) {

    Node* temp = head;
    Node* tempNext = head->next;
    for ( int i = 0; i < k-1; i++ ) {
        tempNext = tempNext->next;
        temp = temp->next;
    }

    Node* insertNode = ( Node* ) malloc ( sizeof( Node ) );
    insertNode->value = num;
    temp->next = insertNode;
    insertNode->prev = temp;
    insertNode->next = tempNext;
    tempNext->prev = insertNode;
    return head;
}