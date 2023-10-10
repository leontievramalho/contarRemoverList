#include <iostream>
using namespace std;

struct no{
	int data;
	no *next;
};

void printList(no *&head){
	no *atual = head;
	cout << "[";
	while(atual != NULL){
		cout << atual -> data << " "; 
		atual = atual -> next;
	}
	cout << "]" << endl;
}

int tamanhoList(no *head){
	int count = 0;
	while(head != NULL){
		count ++;
		head = head -> next;	
	}
	return count;
}

void removerList(no *&head, int pos){
	int count = 0;
	no *atual = head;
	no *anterior = NULL;
	while(atual->next != NULL && count < pos){
		count ++;
		anterior = atual;
		atual = atual -> next;
	}
	if(count != pos){
		cout << "Nao eh possivel deletar, porque nao ha elemento nesse posicao." << endl;
	}else if(count == 0){
		head = head -> next;
		delete atual;
	}else{
		anterior -> next = atual -> next;
		delete atual;
	}
}

int main() {
	
	// criando lista
	no *lista = new no;
	lista -> data = 7;
	lista -> next = NULL;
	
	no *lista2 = new no;
	lista2 -> data = 11;
	lista2 -> next = NULL;
	lista -> next = lista2;
	
	no *lista3 = new no;
	lista3 -> data = 13;
	lista3 -> next = NULL;
	lista2 -> next = lista3;
	
	no *lista4 = new no;
	lista4 -> data = 22;
	lista4 -> next = NULL;
	lista3 -> next = lista4;
	//printando
	printList(lista);
	// tamanho
	cout << "tamanho: " << tamanhoList(lista) << endl;
	// remover
	removerList(lista, 1);
	printList(lista);
	return 0;
}
