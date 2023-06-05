// Implemente uma função que insira elementos sempre ao final da lista. Esta função deve ter o protótipo:
// Lista* lst_insere (Lista* l, int i);
// Para testar esta função, use/implemente as funções de:
// - criação de lista
// - impressão da lista
// - busca último da lista

#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

//função de criação: retorna uma lista vazia
Lista* lst_cria (void){
	return NULL;
}

//função imprime: imprime valores dos elementos
void lst_imprime (Lista* l){
	Lista* p;
	for (p = l; p != NULL; p = p->prox)
		printf("info = %d\n", p->info);
}

void lst_libera (Lista* l){
	Lista* p = l;
	while (p != NULL){
		l = p->prox; //guarda referência p/ próx. elemento
		free(p); //libera a memória apontada por p
	p = l; //faz p apontar para o próximo
	}
}

Lista* ultimo (Lista* l){
	Lista* p=l;
	if (p!=NULL)
		while (p->prox!=NULL)
			p=p->prox;
	return p;
}

//inserção no fim: retorna a lista atualizada
Lista* lst_insere (Lista* l, int i){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox=NULL;
	Lista* ult = ultimo (l);
	if (ult==NULL) //lista vazia
		l=novo;
	else //ha elementos na lista
		ult->prox=novo;
	return l;
}

int main(){
	Lista* l;
	printf ("\nCriando lista....");
	l = lst_cria();
	printf ("\nImprimindo lista....\n");
	lst_imprime (l);
	printf ("\nInserindo elementos na lista....");
	l = lst_insere (l, 10);
	printf ("\nImprimindo lista....\n");
	lst_imprime (l);
	l = lst_insere (l, 20);
	printf ("\nImprimindo lista....\n");
	lst_imprime (l);
	l = lst_insere (l, 30);
	printf ("\nImprimindo lista....\n");
	lst_imprime (l);
	l = lst_insere (l, 40);
	printf ("\nImprimindo lista....\n");
	lst_imprime (l);
	l = lst_insere (l, 50);
	printf ("\nImprimindo lista....\n");
	lst_imprime (l);
	system("PAUSE");
	return 1;
}