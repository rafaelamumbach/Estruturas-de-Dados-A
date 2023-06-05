// Considere listas de valores inteiros e implemente uma função que receba como parâmetro uma
// lista encadeada e um valor inteiro n e divida a lista em duas, de forma a segunda lista começar
// no primeiro nó logo após a ocorrência de n na lista original. A figura a seguir ilustra esta
// separação:
// Essa função deve obedecer ao protótipo: Lista* separa (Lista* l, intn);
// A função deve retornar um ponteiro para a segunda subdivisão da lista original, enquanto l deve
// continuar apontando para o primeiro elemento da primeira subdivisão da lista.

#include <stdio.h>
#include <stdlib.h>

struct lista{
	int info;
	struct lista* prox;
};
typedef struct lista Lista;

Lista* lst_cria (void){
	return NULL;
}

//inserção no início: retorna a lista atualizada
Lista* lst_insere (Lista* l, int i){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

//função imprime: imprime valores dos elementos
void lst_imprime (Lista* l){
	Lista* p;
	for (p = l; p != NULL; p = p->prox)
	printf("\n\tinfo = %d\n", p->info);
}

Lista* separa (Lista* l, int n){
	Lista* p = l;
	Lista* l2= NULL;
	for (p=l; p!=NULL; p=p->prox){
		if (p->info==n){
			l2=p->prox;
			p->prox=NULL;
		}
	}
	return l2;
}

int main (void){
	Lista* l; //declara uma lista não iniciada
	Lista* l2 = NULL;
	l = lst_cria(); //inicia lista vazia
	l = lst_insere(l, 1);
	l = lst_insere(l, 2);
	l = lst_insere(l, 3);
	l = lst_insere(l, 2);
	l = lst_insere(l, 4);
	l = lst_insere(l, 5);
	l = lst_insere(l, 6);
	l = lst_insere(l, 2);
	lst_imprime(l); 
	l2=separa(l,4);
	printf ("Lista 1:\n");
	lst_imprime(l);
	printf ("Lista 2:\n");
	lst_imprime(l2);
	system("pause");
	return 0;
}