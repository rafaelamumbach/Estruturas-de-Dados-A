// Implemente uma função que receba duas listas encadeadas de valores inteiros e
// retorne a lista resultante da concatenação das duas listas recebidas como parâmetros,
// isto é, após a concatenação, o último elemento da primeira lista deve apontar para o
// primeiro elemento da segunda lista. Esta função deve obedecer ao protótipo:
// Lista* concatena (Lista* l1, Lista* l2);

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
Lista* concatena1(Lista* l1, Lista* l2);

/* função de criação: retorna uma lista vazia */
Lista* lst_cria (void)
{
	return NULL;
}

/* inserção no início: retorna a lista atualizada */
Lista* lst_insere (Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

/* função imprime: imprime valores dos elementos */
void lst_imprime (Lista* l)
{
	Lista* p;
	for (p = l; p != NULL; p = p->prox)
		printf("info = %d\n", p->info);
}
void lst_libera (Lista* l)
{
	Lista* p = l;
	while (p != NULL) {
		l = p->prox; /* guarda referência p/ próx. elemento */
		free(p); /* libera a memória apontada por p */
	p = l; /* faz p apontar para o próximo */
	}
}

Lista* ultimo (Lista* l)
{
	Lista* p=l;
	if (p!=NULL)
		while (p->prox!=NULL)
			p=p->prox;
	return p;
}

Lista* concatena1(Lista* l1, Lista* l2)
{
	if (l1==NULL)
		return l2;
	ultimo(l1)->prox=l2;
	return l1;
}

int main (void)
{
	Lista* l1; /* declara uma lista não iniciada */
	l1 = lst_cria(); /* inicia lista vazia */
	l1 = lst_insere(l1, 23); /* insere na lista o elemento 23 */
	l1 = lst_insere(l1, 45); /* insere na lista o elemento 45 */
	l1 = lst_insere(l1, 56); /* insere na lista o elemento 56 */
	l1 = lst_insere(l1, 78); /* insere na lista o elemento 78 */
	printf ("\nLista 1: \n");
	lst_imprime(l1); /* imprimirá: 78 56 45 23 */

	Lista* l2; /* declara uma lista não iniciada */
	l2 = lst_cria(); /* inicia lista vazia */
	l2 = lst_insere(l2, 2); /* insere na lista o elemento 2 */
	l2 = lst_insere(l2, 4); /* insere na lista o elemento 4 */
	l2 = lst_insere(l2, 5); /* insere na lista o elemento 5 */
	l2 = lst_insere(l2, 7); /* insere na lista o elemento 7 */
	printf ("\nLista 2: \n");
	lst_imprime(l2); 	
	
	Lista* l3=concatena1(l1, l2);
	printf ("\nImprimindo lista 3 apos concatenacao na primeira versao de concatena: \n");
	lst_imprime(l3);
	 
	printf ("\nLista 1 apos a concatenacao: \n");
	lst_imprime(l1);
	printf ("\nLista 2 apos a concatenacao: \n");
	lst_imprime(l2); 
	printf ("\n\nNOTEM que a lista 1 foi alterada.... se nao quiserem isso, criem uma lista auxiliar que armazene a concatenacao das duas... \n");		
	lst_libera(l1);
	lst_libera(l2);
	system("pause");
	return 0;
}