#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define fantasma 0

typedef struct Node{
    char item;
    struct Node* next;
}Node;

typedef Node* List;

// prototypes
List newList();
bool emptyList(List A);
int listSize(List A);
List insertList(List A, char n);
char getElement(List A, int m);
Node* searchItem(List A, char n);
List removeFirst(List A);
List emptyList(List A);
List removeLast(List A);
void showList(List A);

// implementation

// creates empty list
List newList(){
    List L = NULL;
    return L;
}

// checks if the list is empty
bool emptyList(List L){
    bool empty = true;
    if(L != NULL) 
        empty = false;
    return empty;
}

// returns size of the list
int listSize(List L){
    int tam = 0;
    Node *aux;

    if(L != NULL){
        aux = L;
        while(aux != NULL){
            tam++;
            aux = aux->next;
        }
    }

    return tam;
}


// insert an element on the list
List insertList(List L, char k){
    Node *novo;
    novo = (Node *) malloc(sizeof(Node));
    novo->item = k;
    novo->next = L;
    L = novo;
    return L;
}

// returns the element at a specific position in the list
char getElement(List L, int k){
    int cont = 1;
    Node *aux, *index;
    char ret = fantasma;

    aux = L; 
    index = aux;

    while((aux != NULL) && (cont <= k)){
        index = aux;
        aux = aux->next;            
        cont++;
    }

    if((index != NULL) && (k == cont-1)) 
        ret = index->item; 

    return ret;
}

// search an element at the 'k' position on the list
Node* searchItem(List L, char k){
    Node *aux = NULL;
    bool sentinela = false;

    if(L != NULL){
        aux = L;
        while((aux != NULL) && (sentinela == false)){
            if(aux->item == k) sentinela = true;
                else aux = aux->next;
        }
    }

    return aux;
}

// removes the first element of the list
List removeFirst(List L){
    Node *aux;

    if(L != NULL){
        aux = L;
        L = L->next;
    }

    return L;
}

// empty the list
List emptyList(List L){
    Node *aux;
    
    if(L != NULL){
        while(L != NULL){
            aux = L;
            L = L->next;
        }
    }

    return L;
}

// removes last element of the list
List removeLast(List L){
    Node* aux, *prox;
    
    if(L != NULL){
        aux = L; prox = aux;

        while(prox->next != NULL){
            aux = prox;
            prox = prox->next;
        }

        if(prox->next == NULL && prox != aux){ 
            aux->next = NULL; 
        }
        
        else{ 
            L = NULL;
        }
    }

    return L;
}

void showList(List L){
    Node *aux;

    if(L != NULL){
        aux = L;
        while(aux != NULL){
            printf("%c ", aux->item);
            aux = aux->next;
        }
    }
    printf("\n");
}