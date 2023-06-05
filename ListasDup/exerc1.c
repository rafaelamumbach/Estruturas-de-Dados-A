// Teste as funções implementadas. Na medida do possível, reuse as funções básicas vistas em sala de aula, sempre
// que necessário.
// 1. Implemente uma função que insira elementos sempre ao final da lista. Esta função deve ter o protótipo:
// Lista2* lst_insere (Lista2* l, int i);
// Para testar esta função, use/implemente as funções de:
// - criação de lista
// - impressão da lista
// - busca último da lista

#include <stdio.h>
#include <stdlib.h>

struct lista2{
int info;
struct lista2* ant;
struct lista2* prox;
};
typedef struct lista2 Lista2;

//função de criação: retorna uma lista vazia
Lista2* lst_cria (void){
	return NULL;
}

Lista2* ultimo (Lista2* l){
	Lista2* p=l;
	if (p!=NULL)
		while (p->prox!=NULL)
			p=p->prox;
	return p;
}

//inserção no fim: retorna a lista atualizada
Lista2* lst_insere (Lista2* l, int i){
	Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
	novo->info = i;
	novo->prox=NULL;
	Lista2* ult = ultimo (l);
	if (ult==NULL) //lista vazia
		l=novo;
	else //ha elementos na lista
		ult->prox=novo;
	novo->ant=ult;
	return l;
}

//função imprime: imprime valores dos elementos
void lst_imprime (Lista2* l){
	Lista2* p;
	for (p = l; p != NULL; p = p->prox)
	printf("\n\tinfo = %d\n", p->info);
}

int main(){
	Lista2* l;
	printf ("\nCriando lista....");
	l = lst_cria();
	printf ("\nImprimindo lista....");
	lst_imprime (l);
	printf ("\nInserindo elementos na lista....");
	l = lst_insere (l, 10);
	printf ("\nImprimindo lista....");
	lst_imprime (l);
	l = lst_insere (l, 20);
	printf ("\nImprimindo lista....");
	lst_imprime (l);
	l = lst_insere (l, 30);
	printf ("\nImprimindo lista....");
	lst_imprime (l);
	l = lst_insere (l, 40);
	printf ("\nImprimindo lista....");
	lst_imprime (l);
	l = lst_insere (l, 50);
	printf ("\nImprimindo lista....");
	lst_imprime (l);
	system("PAUSE");
	return 1;
}