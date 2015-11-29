#include <iostream>
#include <stdlib.h>

using namespace std;

#define INICIO 1
#define MAXTAM 100

struct Celula {
	int chave;
	struct Celula *prox;
};

struct Lista {
	struct Celula *primeiro, *ultimo;
};

void FLVazia(struct Lista *lista) {
	lista->primeiro = (struct Celula*) malloc(sizeof(struct Celula));
	lista->ultimo = lista->primeiro;
	lista->primeiro->prox = NULL;
}

int Vazia(struct Lista lista) {
	return (lista.primeiro == lista.ultimo);
}

void Insere(struct Lista *lista, int x) {
	lista->ultimo->prox = (struct Celula*) malloc(sizeof(struct Celula));
	lista->ultimo = lista->ultimo->prox;
	lista->ultimo->chave = x;
	lista->ultimo->prox = NULL;
}

void RetiraPorChave(struct Lista *lista, int x) {
	struct Celula *aux, *exc;
	
	if(Vazia(*lista)) {
		cout << "Lista esta vazia\n";
		return;
	}
	
	aux = lista->primeiro;
	
	while(aux != NULL) {
		if(aux->prox == NULL) {
			cout << "Elemento nao encontrado";
			return;
		} else if(aux->prox->chave == x) {
			exc = aux->prox;
			aux->prox = aux->prox->prox;
			
			if (aux->prox == NULL)
				lista->ultimo = aux;
				
			free(exc);
			return;
		}
		aux = aux->prox;
	}	
}

void Retira(struct Lista *lista, struct Celula *p) {
	struct Celula *aux;
	if(Vazia(*lista) || p == NULL || p->prox == NULL) {
		cout << "Erro: Lista vazia ou posicao nao existe\n";
		return;
	}
	aux = p->prox;
	p->prox = aux->prox;
	if(p->prox == NULL)
		lista->ultimo = p;
		
	free(aux);
}

void Imprime(struct Lista lista) {
	cout << "\n\n---Lista---\n\n";
	struct Celula *aux;
	aux = lista.primeiro->prox;
	while(aux != NULL) {
		cout << "\n Chave: " << aux->chave;
		aux = aux->prox;
	}
}

// Concatena uma lista no final da primeira
void funcao4a(struct Lista *lista1, struct Lista *lista2) {
	lista1->ultimo->prox = lista2->primeiro->prox;
}

// Copia todos os elementos da lista 1 para a lista 2
void funcao4b(struct Lista lista1, struct Lista *lista2) {
	struct Celula *aux;
	if(Vazia(lista1)) {
		cout << "Erro: lista vazia!";
		return;
	}
	aux = lista1.primeiro->prox;
	while(aux != NULL) {
		Insere(lista2, aux->chave);
		aux = aux->prox;
	}
}

void funcao4c(struct Lista *lista, int x) {
	struct Celula *aux;
	aux = lista->primeiro;
	struct Celula *novo = (struct Celula*) malloc(sizeof(struct Celula));
	while(aux != NULL) {
		if(aux->prox == NULL || aux->prox->chave > x) {
			novo->prox = aux->prox;
			novo->chave = x;
			aux->prox = novo;
			if(aux->prox->prox == NULL)
				lista->ultimo = aux->prox;
			return;
		}
		aux = aux->prox;
	}
}

void funcao4d(struct Lista *lista) {
	
}

int main() {
	struct Lista l1, l2;
	FLVazia(&l1);
	FLVazia(&l2);
	
	Insere(&l1, 99);
	Insere(&l1, 19);
	Insere(&l1, 1);
	Insere(&l1, 44);
	Insere(&l1, 19);
	Insere(&l1, 27);
	Insere(&l1, 127);	
	Imprime(l1);
	
	Insere(&l2, 98);
	Insere(&l2, 18);
	Insere(&l2, 8);
	Insere(&l2, 48);
	Insere(&l2, 15);
	Insere(&l2, 28);
	Insere(&l2, 12);	
	Imprime(l2);
	
	cout << "\n\n\n---------funcao4a--------\n";
	funcao4a(&l1, &l2);
	Imprime(l1);
	cout << "\n-------------fim---------\n";
	
	cout << "\n\n\n---------funcao4b--------\n";
	FLVazia(&l2);
	funcao4b(l1, &l2);
	Imprime(l1);
	Imprime(l2);
	cout << "\n-------------fim---------\n";
	
	cout << "\n\n\n---------funcao4c--------\n";
	FLVazia(&l2);
	funcao4c(&l2, 99);
	funcao4c(&l2, 98);
	funcao4c(&l2, 18);
	funcao4c(&l2, 8);
	funcao4c(&l2, 48);
	funcao4c(&l2, 15);
	funcao4c(&l2, 28);
	funcao4c(&l2, 12);	
	Imprime(l2);
	cout << "\n-------------fim---------\n";
	
	RetiraPorChave(&l1, 44);
	cout << "\nRetirou a chave 44\n";
	Imprime(l1);
		
	RetiraPorChave(&l1, 27);
	cout << "\nRetirou a chave 27\n";
	Imprime(l1);
		
	RetiraPorChave(&l1, 100);
	cout << "\nRetirou a chave 100\n";
	Imprime(l1);
	
	RetiraPorChave(&l1, 1);
	cout << "\nRetirou a chave 1\n";
	Imprime(l1);
}








