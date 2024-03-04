#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define Max 10

typedef struct {
	int comprimento;
	int Vetor[Max];
} Lista;

typedef struct {
	int comprimento;
	int tab[Max];
} Heap;

void construirHeapMinima(Heap*, Lista);
// void mostrarLista(Lista);              
Lista construirLista(int);      
void trocar(Heap *lista, int m, int n);
void inserirHeap(Heap *A, int valor);
Heap criarHeap();
void restauraHeapAbaixo(Heap* A, int x);

int main(){
	Lista A;
	Heap HM;
	int m;
	A = construirLista(m);
	construirHeapMinima(&HM, A);
	return 0;
}

Lista construirLista(int n){
         Lista listaA;
         int i,t;
         if (n==0)  listaA.comprimento = n;
         else {
               if((n > 0) && (n <= Max)) t = n; 
               else t = Max;
               listaA.comprimento = t;
               for(i=0;i<t;i++) listaA.Vetor[i] = 65+i;
         }
         return listaA;
}

Heap criarHeap(){
    Heap A;
    A.comprimento = 0;
    return A;
}

void restauraHeapAcima(Heap *A, int x, int y){
    if((y > 1) && (x != 0)){
        int valor_y = A->tab[y]; 
        int valor_x = A->tab[x];
        if(valor_y > valor_x){
            trocar(A, x, y);
            restauraHeapAcima(A, floor(x/2), floor(y/2));
        }
    }
}

void inserirHeap(Heap *A, int valor){
    if(A->comprimento < Max){
        int i = ++A->comprimento;
        A->tab[i] = valor;
        restauraHeapAcima(A, floor(i/2), i);
    }
}

void trocar(Heap *lista, int m, int n){
    if(lista->comprimento >= 2){
        int valor = lista->tab[m];
        lista->tab[m] = lista->tab[n];
        lista->tab[n] = valor;
    }
}

void restauraHeapAbaixo(Heap* A, int x){
    if(A->comprimento >= 2){
        int esq = x*2;
        if(esq <= A->comprimento){
            int dir = x*2+1;
            int indice = esq;
            if(dir <= A->comprimento){
                if(A->tab[dir] > A->tab[esq]) indice = dir;
            }
            if(A->tab[indice] > A->tab[x]){
                trocar(A, x, indice);
                restauraHeapAbaixo(A, indice);
            }
        }
    }
}

void acessarPrimeiro(Heap* A){
    if(A->comprimento >= 1){
        A->tab[A->comprimento];
        A->tab[1] = A->tab[A->comprimento];
        --A->comprimento;
        restauraHeapAbaixo(A, 1);
    }
}