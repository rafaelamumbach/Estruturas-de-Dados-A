// Implemente uma função que receba como parâmetro uma lista encadeada e inverta o
// encadeamento de seus nós, retornando a lista resultante. Após a execução desta função, cada
// nó da lista vai estar apontando para o nó que originalmente era seu antecessor, e o último nó da
// lista passará a ser o primeiro nó da lista invertida, conforme ilustrado a seguir:
// Esta função deve obedecer ao protótipo: Lista* inverte (Lista* l);


#include <stdio.h>
#include <stdlib.h>

struct lista
{
	int info;
	struct lista* prox;
};
typedef struct lista Lista;

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
		printf("\n\tinfo = %d\n", p->info);
}

Lista* inverte(Lista* l){
	Lista* p;
	Lista* pos; // posterior
	Lista* ant; //anterior
	Lista* aux;
	p = l;
	if (p){
		pos = p ->prox;
		while( pos != NULL){
			ant = p;
			p = pos;
			pos = p->prox;
			p->prox=ant;
		} 
		l->prox = NULL;
		l =p;
	}
	return l;
}

int main (void){
	Lista* l; /* declara uma lista não iniciada */
	l = lst_cria(); /* inicia lista vazia */
	l = lst_insere(l, 1);
	l = lst_insere(l, 2);
	l = lst_insere(l, 3);
	l = lst_insere(l, 4);
	l = lst_insere(l, 5);
	printf ("Lista normal:\n"); lst_imprime(l);
	l = inverte(l);
	printf ("Lista invertida:\n"); lst_imprime(l);
	system("pause");
	return 0;
}