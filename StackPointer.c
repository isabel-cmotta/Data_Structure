#include <stdio.h>
#include <stdlib.h>

#define fanstasma 0

typedef struct Node{
    unsigned char item;
    struct Node* next;
}Node;

typedef Node* Stack;

Stack newStack();
Stack pushStack(Stack A, int item);
Stack popStack(Stack A);
void showStack();
Stack emptyStack(Stack A);

Stack newStack(){
    Stack A;
    A = NULL;
    return A;
}

Stack pushStack(Stack A, int item){
    Node* aux, *new;

    new = (Node *) malloc(sizeof(Node));

    if(new != NULL){
        new->item = item;
        if(A == NULL){
            new->next = A;
            A = new;
        }else{
            aux = A;
            while(aux->next != NULL){
                aux = aux->next;
            }
            new->next = NULL;
            aux->next = new;
        }
    }

    return A;
}

Stack popStack(Stack A){
    Node* aux, *pre;

    if(A != NULL){
        if(A->next == NULL){
            aux = A;
            A = NULL;

        }else{
            aux = A;
            while(aux->next != NULL){
                pre = aux;
                aux = aux->next;
            }
            pre->next = NULL;
        }
    }

    return A;
}

void showStack(Stack A){
    Node* aux;

    if(A != NULL){
        aux = A;
        while(aux != NULL){
            printf("%d\n", aux->item);
            aux = aux->next;
        }
        printf("\n");
    }
}