#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 100
#define ghost 0
#define sinal -1

typedef struct{
	int start;
	int end;
	int array[Max];
} q_Queue;

typedef q_Queue* Queue;

//interface
Queue createQueue();
bool emptyQueue(Queue);
bool fullQueue(Queue);
int firstQueue(Queue);
Queue pushQueue(Queue, int);
Queue popQueue(Queue);
void showQueue(Queue);

int main(){
	Queue A, B;
	int get, k;
	A = createQueue();
	bool emptyQueue(A);
	get = firstQueue(A);
	B = pushQueue(A,k);
	B = popQueue(A);
	showQueue(A);
}

// create empty queue
Queue createQueue(){
	Queue queue;
	queue = (q_Queue*) malloc(sizeof(q_Queue));
	queue->start = sinal;
	queue->end = sinal;
	return queue;
}

// clear the content of the queue
bool emptyQueue(Queue queue){
	bool empty = false;
	if(queue->start == sinal) 
		empty = true;
	return empty;
}

// checks if the queue is full
bool fullQueue(Queue queue){
	bool full = false;
	int aux = (queue->start + 1) % Max;
	if(aux == queue->end) 
		full = true;
	return full;
}

// access the first element of the queue
int firstQueue(Queue queue){
	int y, p;
	y = ghost;
	if(queue->start != sinal){
		p = queue->start;
		y = queue->array[p];
	}
	return y;
}

// add an element to the end of the queue
Queue pushQueue(Queue queue, int value){
	int aux = (queue->start + 1) % Max;
	
	if (aux != queue->start){
		queue->array[aux] = value;
		if(queue->start == sinal)
			queue->start = aux;
		queue->end = aux;
	}
	
	return queue;
}

// remove the first element of the queue
Queue popQueue(Queue queue){
	int aux = (queue->start + 1) % Max;
	
	if(queue->start != sinal){
		if(queue->start == queue->end){
			queue->start = sinal;
			queue->end = sinal;
		}
		else queue->start = aux;
	}	
	return queue;
}

void showQueue(Queue queue){
	int aux = queue->start - 1;
	
	if(queue->start == sinal)
		printf("Queue is Empty!");
	else{
		do{
			aux = (aux + 1) % Max;
			printf("%d ", queue->array[aux]);
		}while(aux != queue->end);
	}
}