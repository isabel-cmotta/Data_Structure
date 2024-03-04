#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 10
#define sinal -1
#define fantasma 0

typedef struct {
      int top;	 
      float tab[Max];
} p_Stack;

typedef p_Stack *Stack;

// prototypes
Stack newStack();
float firstTop(Stack);
bool emptyStack(Stack);
bool fullStack(Stack);
void pushStack(Stack, float);
void popStack(Stack);
void showStack(Stack P);

//implementation

// create empty stack
Stack newStack(){
	Stack A;
	A->top = 0;
	return A;
}

// checks is stack is empty
bool emptyStack(Stack P){
	bool empty = false;

	if(P->top == sinal)
		empty = true;

	return empty;
}

// checks is stack is full
bool fullStack(Stack P){
	bool full = false;

	if(P->top == Max)
		full = true;

	return full;
}

// access the element at the top of the stack
float firstTop(Stack P){
	float value;
	int k;
	k = P->top;

	if(k != sinal){
		value = P->tab[k-1];
	}

	return value;
}     

// add an element to the stack
void pushStack(Stack P, float y){
	int tam = P->top;

	if(tam != Max){
		P->tab[tam] = y;
		P->top++;
	}
}

// remove an element from the stack
void popStack(Stack P){	
	int tam = P->top;

	if(P->top != sinal){
		P->top--;
	}
}

void showStack(Stack P){
	for(int i = 0; i < P->top; i++){
		printf("%.1f\n", P->tab[i]);
	}
}