#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN 100000

typedef struct Node {
    char arr[MAXLEN];
    struct Node* next;
} Node;

Node* Insert( Node* head, char arr[MAXLEN] );
int Quary( Node* head, char arr[MAXLEN] );

int main() {
    Node* head = ( Node* ) malloc ( sizeof(Node) );
    head->next = NULL;
    strcpy( head->arr, "START HEAD");
    head = Insert( head, "abc");
    head = Insert( head, "abc");
    head = Insert( head, "abc");
    head = Insert( head, "cde");
    int sum = Quary( head, "cde" );
    printf("sum = %d\n",sum);
    return 0;
}

Node* Insert( Node* head, char arr[MAXLEN] ) {
    Node* temp = ( Node* ) malloc ( sizeof(Node) );
    strcpy( temp->arr, arr);
    if ( head->next == NULL ) {
        head->next = temp;
        return head;
    } 
    temp->next = head->next;
    head->next = temp;
    return head;
}

int Quary( Node* head, char arr[MAXLEN] ) {
    int sum = 0;
    Node* temp = head->next;
    while ( temp->next != NULL ) {       
        if ( strcmp(temp->arr, arr) == 0 ) sum += 1;
        temp = temp->next;
    }
    if ( strcmp(temp->arr, arr) == 0 ) sum += 1;
    return sum;
}

