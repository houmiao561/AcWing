#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 数字栈结构体定义
typedef struct NumNode {
    int value;
    struct NumNode* next;
} NumNode;

// 运算符栈结构体定义
typedef struct SigNode {
    char sig;
    struct SigNode* next;
} SigNode;

int cal( int x1, int x2 ,char signal );
int allString( char* head );
NumNode* Push( NumNode* head, int num );
NumNode* Pop( NumNode* head );
SigNode* SigPop( SigNode* head );
SigNode* SigPush( SigNode* head, char num );


int main() {
    char str[] = "(2+2)*(1+1)";
    char *p = str; // 指针指向字符串首地址

    // 主要函数
    int sum = allString(p);
    //printf("sum = %d",sum);

    return 0;
}

// 主要函数
int allString( char* head ) {
    int sum = 0;
    int tempNum = 0;
    char tempSig = ' ';

    // 建立数字栈, head指向头节点 -> 栈顶 -> 栈底
    NumNode* temp = (NumNode*) malloc ( sizeof(NumNode) );
    temp->next = NULL;
    temp->value = 0;

    // 建立运算符栈, head指向头节点 -> 栈顶 -> 栈底
    SigNode* Sigtemp = (SigNode*) malloc ( sizeof(SigNode) );
    Sigtemp->next = NULL;
    Sigtemp->sig = '_'; // 头节点是 '_'

    while ( *head != '\0' ) {
        // printf("当前字符: %c\n", *head); 测试while没问题
        switch ( *head ) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
            case ')':
                // 符号栈
                tempSig = *head;
                Sigtemp = SigPush(Sigtemp,tempSig);
                break;
            // case '(':
            // case ')':
                // printf("!!!\n");
                // break;
            default:
                // 数字栈
                tempNum = *head - '0';
                temp = Push(temp,tempNum);
                break;
                // 1 -> 1 -> 2 -> 2 逆序的了
        }
        head ++;
    }

    // 测试数字栈压栈效果，压栈没问题
    while (temp->next != NULL) {
        printf("测试TEMP = %d\n",temp->value);
        temp = temp->next;
    }
    printf("测试TEMP = %d\n",temp->value);


    // 测试符号栈压栈效果，压栈没问题
    while (Sigtemp->next != NULL) {
        printf("测试TEMPSIG = %c\n",Sigtemp->sig);
        Sigtemp = Sigtemp->next;
    }
    printf("测试TEMPSIG = %c\n",Sigtemp->sig);


    /*
    两个栈都已经建立好了
    栈没有问题
    后面的思路是啥啊
    */










    return sum;
}




// 运算封装函数
int cal( int x1, int x2 ,char signal ) {
    switch (signal) {
        case '+': return x1 + x2;
        case '-': return x1 - x2;
        case '*': return x1 * x2;
        case '/': return x1 / x2;
    }
    return 0;
}

// 数字栈压栈
NumNode* Push( NumNode* head, int num ){
    NumNode* temp = (NumNode*) malloc ( sizeof(NumNode) );
    temp->value = num;
    if ( head->next != NULL ) temp->next = head->next;
    head->next = temp;
    return head;
}

// 数字栈弹出
NumNode* Pop( NumNode* head ) {
    NumNode* temp = head->next; // free temp
    head->next = head->next->next;
    free(temp);
    return head;
}


// 运算符栈压栈
SigNode* SigPush( SigNode* head, char num ){
    SigNode* temp = (SigNode*) malloc ( sizeof(SigNode) );
    temp->sig = num;
    if ( head->next != NULL ) temp->next = head->next;
    head->next = temp;
    return head;
}

// 运算符栈弹出
SigNode* SigPop( SigNode* head ) {
    SigNode* temp = head->next; // free temp
    head->next = head->next->next;
    free(temp);
    return head;
}
