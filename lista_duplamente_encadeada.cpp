#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAXTAM 10

struct Celula {
	int chave;
	struct Celula *prox, *ant;
};

struct ListaDE {
	struct Celula *primeiro, *ultimo;
};

void FLVazia(struct ListaDE *lista) {
	lista->primeiro = (struct Celula*) malloc (sizeof(struct Celula));
	lista->ultimo = lista->primeiro;
	lista->primeiro->ant = NULL;
	lista->primeiro->prox = NULL;
}

int Vazia(struct ListaDE lista) {
	return (lista.primeiro == lista.ultimo);
}

void InsereNoFinal(struct ListaDE *lista, int x) {
	lista->ultimo->prox = (struct Celula*) malloc(sizeof(struct Celula));
	lista->ultimo->prox->ant = lista->ultimo;
	lista->ultimo = lista->ultimo->prox;
	lista->ultimo->chave = x;
	lista->ultimo->prox = NULL;
}

void Retira(struct ListaDE *lista, int x) {
	if(Vazia(*lista)) {
		cout << "Erro: Lista vazia!\n";
		return;
	}
	struct Celula *aux;
	aux = lista->primeiro->prox;
	while(aux != NULL) {
		if(aux->chave == x) {
			aux->ant->prox = aux->prox;
			if (aux->prox == NULL)
				lista->ultimo = aux->ant;
			else {
				aux->prox->ant = aux->ant;
				free(aux);
				return;
			}
			aux = aux->prox;
		}
	}
}

void Imprime(struct ListaDE lista) {
	cout << "\n---- Lista duplamente encadeada ----\n\n";
	struct Celula *aux;
	aux = lista.primeiro->prox;
	while(aux != NULL) {
		cout << "Chave: " << aux->chave << "- End. Atual: " << aux << " Ant: " << aux->ant << " Prox: " << aux->prox << "\n";
		aux = aux->prox;
	}
}

main() {
	struct ListaDE lista;
	FLVazia(&lista);
	cout << "\nInserindo elementos na lista:\n";
	InsereNoFinal(&lista, 199);
	InsereNoFinal(&lista, 100);
	InsereNoFinal(&lista, 102);
	InsereNoFinal(&lista, 104);
	InsereNoFinal(&lista, 105);
	Imprime(lista);
	cout << "\nRetirada do elemento 102 da lista:\n";
	Retira(&lista, 102);
	Imprime(lista);
	cout << "\nRetirada do elemento 105 da lista:\n";
	Retira(&lista, 105);
	Imprime(lista);
}













