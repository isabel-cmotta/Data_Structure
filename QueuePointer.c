#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Cel{
	void * value;       // value is a pointer
	struct Cel *next; // next keeps the address from the next element on the queue 
}Cel;

typedef struct{
	Cel *start;
	Cel *end;
}Queue;

// prototypes 
void createQueue(Queue *);  
void *firstQueue(Queue *);  
bool emptyQueue(Queue *);  
void pushQueue(Queue *, void *);  
void popQueue(Queue *);          


// implementation

// creates empty queue
void createQueue(Queue *Q){
    Q->start = NULL;
    Q->end = NULL;   
}

// access the first element of the queue
void *firstQueue(Queue *Q){
    Cel *aux;
    void * item;
    aux = Q->start; 
    if (aux == NULL) item = NULL;
    else item = aux->value;
    return item;
}

// checks if the queue is empty
bool emptyQueue(Queue *Q){
    bool empty;
    Cel *aux;
    aux = Q->start; 
    if (aux == NULL) empty = true;
    else empty = false;
    return empty;
}

// add an element to the end of the queue
void pushQueue(Queue *Q, void *ap){
    Cel *p;
    Cel *aux;
    p = (Cel *)malloc(sizeof(Cel));
    p->value = ap; p->next = NULL;
    if (Q->start == NULL) Q->start = p;
    else {aux = Q->end;  aux->next = p;}
    Q->end = p;   
}

// remove the first element of the queue
void popQueue(Queue *Q){
    Cel *sec;
    Cel *fir;
    fir = Q->start; 
    if (Q->start != NULL){
        if (Q->start == Q->end) {Q->start = NULL; Q->end = NULL;}
        else {sec = fir->next; Q->start = sec;}
    }
}
