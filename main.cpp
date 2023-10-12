#include <iostream>
using namespace std;

struct no{
	int data;
	no *next;
};

struct noD{
	int data;
	noD *next;
	noD *prev;
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


void printCircleListTwoTimes(no *&head){
	no *atual = head;
	int count = 0;
	cout << "[";
	while(count<2){
		if(atual -> next == head){
			count ++;
		}
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

int meioList(no *&head){
	no *atual = head;
	int count = 0;
	int meioIndex = (tamanhoList(head)-1)/2;
	while(count < meioIndex){
		count ++;
		atual = atual -> next;
	}
	return atual -> data;
}

void circleList(no *&head){
	no *tail = head;
	while(tail -> next != NULL){
		tail = tail -> next;
	}
	tail -> next = head;
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

void printListD(noD *&head){
	noD *atual = head;
	cout << "[";
	while(atual != NULL){
		cout << atual -> data << " "; 
		atual = atual -> next;
	}
	cout << "]" << endl;
}

int maiorNoD(noD *&head){
	noD *atual = head;
	int maior = head -> data;
	while(atual != NULL){
		if(atual -> data > maior){
			maior = atual -> data;
		}
		atual = atual -> next;
	}
	return maior;
}

int tamanhoListD(noD *head){
	int count = 0;
	while(head != NULL){
		count ++;
		head = head -> next;	
	}
	return count;
}

void inserirListD(noD *&head, noD *novoNo, int pos){
	int count = 0;
	noD *atual = head;
	while(atual->next != NULL && count < pos){
		count ++;
		atual = atual -> next;
	}
	if(count != pos && count+1 != pos){
		cout << "Nao eh possivel acrescentar, porque essa posicao esta muito alem." << endl;
	}else if(count == 0){
		novoNo -> next = head;
		novoNo -> prev = NULL;
		head -> prev = novoNo;
	}else{
		noD *anterior = atual -> prev;
		novoNo -> prev = anterior;
		anterior -> next = novoNo;
		atual -> prev = novoNo;
		novoNo -> next = atual;
	}
}

noD* encontrarD(noD *&head, int pos){
	int count = 0;
	noD *atual = head;
	while(atual->next != NULL && count < pos){
		count ++;
		atual = atual -> next;
	}
	if(count == pos){
		return atual;
	}
	return NULL;
}

void merge(noD *&head, int inicio, int meio, int final){
	noD *esquerda = encontrarD(head, inicio);
	noD *fimEsquerda = encontrarD(head, meio);
	noD *direita = fimEsquerda -> next;
	fimEsquerda -> next = NULL;
	direita -> prev = NULL; 
	
	int tamEsq = tamanhoListD(esquerda);
	int tamDir = tamanhoListD(direita);
	
	int i = 0;
	int j = 0;
	int k = inicio;
	
	while(i < tamEsq && j < tamDir){
		if(encontrarD(esquerda, i)<=encontrarD(direita, j)){
			noD *atual = head;
			while(atual != encontrarD(esquerda, i)){
				atual = atual -> next;
			}
			noD *anterior = atual -> prev;
			noD *posterior = atual -> next;
			if(anterior!=NULL){
				anterior -> next = posterior;
			}
			if(posterior!=NULL){
				posterior -> prev = anterior;
			}
			delete atual;
			inserirListD(head, encontrarD(esquerda, i), k);
			i++;
			k++;
		} else{
			noD *atual = head;
			while(atual != encontrarD(direita, j)){
				atual = atual -> next;
			}
			noD *anterior = atual -> prev;
			noD *posterior = atual -> next;
			if(anterior!=NULL){
				anterior -> next = posterior;
			}
			if(posterior!=NULL){
				posterior -> prev = anterior;
			}
			delete atual;
			inserirListD(head, encontrarD(direita, j), k);
			j++;
			k++;
		}
	}
	while(i < tamEsq){
		noD *atual = head;
		while(atual != encontrarD(esquerda, i)){
			atual = atual -> next;
		}
		noD *anterior = atual -> prev;
		noD *posterior = atual -> next;
		if(anterior!=NULL){
			anterior -> next = posterior;
		}
		if(posterior!=NULL){
			posterior -> prev = anterior;
		}
		delete atual;
		inserirListD(head, encontrarD(esquerda, i), k);
		i++;
		k++;
	}
	while(j < tamDir){
		noD *atual = head;
		while(atual != encontrarD(direita, j)){
			atual = atual -> next;
		}
		noD *anterior = atual -> prev;
		noD *posterior = atual -> next;
		if(anterior!=NULL){
			anterior -> next = posterior;
		}
		if(posterior!=NULL){
			posterior -> prev = anterior;
		}
		delete atual;
		inserirListD(head, encontrarD(direita, j), k);
		j++;
		k++;
	}
}

void mergeListD(noD *&head, int inicio, int final){
	if(inicio<final){
		int meio = (inicio + final)/2;
		mergeListD(head, inicio, meio);
		mergeListD(head, meio + 1, final);
		merge(head, inicio, meio, final);
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
	cout << "removendo da posicao 1"<< endl;
	removerList(lista, 1);
	printList(lista);
	// meio da lista
	cout << "meio: " << meioList(lista) << endl;

	// converter em lista circular
	circleList(lista);
	// printar dando duas voltas para testar se realmente está no formato circular
	cout << "lista circurlar (2 voltas) = " << endl;
	printCircleListTwoTimes(lista);
	
	//criando lista duplamente encadeada
	noD *listaD = new noD;
	listaD -> data = 8;
	listaD -> next = NULL;
	listaD -> prev = NULL;
	
	noD *listaD2 = new noD;
	listaD2 -> data = 11;
	listaD2 -> next = NULL;
	listaD -> next = listaD2;
	listaD2 -> prev = listaD;
	
	noD *listaD3 = new noD;
	listaD3 -> data = -15;
	listaD3 -> next = NULL;
	listaD2 -> next = listaD3;
	listaD3 -> prev = listaD2;
	
	noD *listaD4 = new noD;
	listaD4 -> data = 10;
	listaD4 -> next = NULL;
	listaD3 -> next = listaD4;
	listaD4 -> prev = listaD3;
	
	// exibindo
	printListD(listaD);
	// maior no da lista
	cout << "maior no da lista = " << maiorNoD(listaD) << endl;
	// ordenando
	mergeListD(listaD, 0, tamanhoListD(listaD) - 1);
	printListD(listaD);
	return 0;
}
