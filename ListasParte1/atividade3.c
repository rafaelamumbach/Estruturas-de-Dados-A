// Implemente uma função que tenha como valor de retorno o ponteiro para o último nó
// de uma lista encadeada. Esta função deve obedecer ao protótipo:
// Lista* ultimo (Lista* l);

#include <stdio.h>
#include <stdlib.h>

struct lista{
	int info;
	struct lista* prox;
};
typedef struct lista Lista;

Lista* lst_cria (void);
Lista* lst_insere (Lista* l, int i);
void lst_imprime (Lista* l);
void lst_libera (Lista* l);
Lista* ultimo (Lista* l);

//função de criação: retorna uma lista vazia
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
		printf("info = %d\n", p->info);
}

void lst_libera (Lista* l){
	Lista* p = l;
	while (p != NULL) {
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

int main (void){
	Lista* l; //declara uma lista não iniciada
	l = lst_cria(); //inicia lista vazia
	l = lst_insere(l, 23); //insere na lista o elemento 23
	l = lst_insere(l, 45); //insere na lista o elemento 45
	l = lst_insere(l, 56); //insere na lista o elemento 56
	l = lst_insere(l, 78); //insere na lista o elemento 78
	Lista* ult = ultimo (l);
	if (ult!=NULL)
		printf ("\nO ultimo no da lista eh o %d no endereco %p e o proximo eh null (%p)\n", ult->info, ult, ult->prox);
	else
		printf ("\nLista Vazia\n");
	lst_imprime(l); /* imprimirá: 78 56 45 23 */
	lst_libera(l);
	system("pause");
	return 0;
}
