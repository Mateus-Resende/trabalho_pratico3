#include <iostream>
#include <stdlib.h>

using namespace std;

#define INICIO 1
#define MAXTAM 100

struct Item {
  int chave;
};

struct Lista {
  Item item[MAXTAM];
  int primeiro, ultimo;
};

void FLVazia(Lista *lista) {
  lista->primeiro = INICIO;
  lista->ultimo = lista->primeiro;
}

bool Vazia(Lista lista) {
  return (lista.primeiro == lista.ultimo)
}

void Insere(Lista *lista, Item x) {
  if(lista->ultimo > MAXTAM)
    cout << "Lista esta cheia!\n";
  else{
    lista->item[lista->ultimo - 1] = x;
    lista->ultimo++;
  }   
}

void Retira(Lista *lista, Item *item, int p) {
	int aux;
	if(Vazia(*lista) || p >= lista->ultimo) {
		cout << "Erro: posicao nao existe\n";
		return;
	}
	*item = lista->item[p - 1];
	lista->ultimo--;
	for(aux = p; aux < lista->ultimo; aux++) {
		lista->item[aux - 1] = lista->item[aux];
	}
}

void Imprime(Lista lista) {
	int aux;
	for(aux = lista.primeiro - 1; aux < (lista.ultimo - 1); aux++)
		cout << lista.item[aux].chave << "\n";
}

int main() {
  Lista lista;
  Item item;
  int i, j, k, n, max;
	
  for(i = 0; i < max; i++) {
  	cout << "Informe a chave do item: ";
  	cin >> item.chave;
  	Insere(item, &lista);
  	cout << "Inseriu: " << item.chave << "\n";
  }
  
  cout << "Valores da lista";
  Imprime(lista);
  
  int p;
  cout << "Escolha um elemento para retirar: ";
  cin >> p;
  Retira(&lista, &item, p);
  cout << "Valores da lista";
  Imprime(lista);  
}
