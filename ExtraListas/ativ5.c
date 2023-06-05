// Considere listas que armazenam cadeias de caracteres e implemente uma função para testar se
// duas listas passadas como parâmetros são iguais. Essa função deve obedecer ao protótipo: int
// igual (Lista* l1, Lista* l2);

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

int igual(Lista* l1, Lista* l2){
	while (l1!=NULL && l2!=NULL){
		if (l1->info == l2->info){
			l1 = l1->prox;
			l2 = l2->prox;
		}
		else
			return 0;
	}
	if (l1==NULL && l2==NULL)
		return 1;
	else
		return 0;
}

int main (void){
	Lista* l; //declara uma lista não iniciada
	Lista* l2;
	l = lst_cria(); //inicia lista vazia
	l2 = lst_cria();
	l = lst_insere(l, 1);
	l = lst_insere(l, 2);
	printf ("\nLista 1:\n"); 
	lst_imprime(l);	
	l2 = lst_insere(l2, 1);
	l2 = lst_insere(l2, 2);
	printf ("\nLista 2:\n"); 
	lst_imprime(l2);
	int i=igual(l,l2);
	if (i == 1)
		printf ("\nListas iguais\n");
	else
		printf ("\nListas diferentes\n");
	system("pause");
	return 0;
}