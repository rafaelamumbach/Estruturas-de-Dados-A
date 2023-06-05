// Implemente uma função que calcule a média aritmética dos valores armazenados. Esta função deve ter o
// protótipo:
// Lista* lst_calculaMedia (Lista* l);
// Para testar esta função, use/implemente as funções de:
// - criação de lista
// - inserção na lista
// - impressão da lista

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
	while (p != NULL) {
		l = p->prox; //guarda referência p/ próx. elemento */
		free(p); //libera a memória apontada por p */
	p = l; //faz p apontar para o próximo */
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
	if (ult==NULL)//lista vazia
		l=novo;
	else //ha elementos na lista
		ult->prox=novo;
	return l;
}

float lst_calculaMedia (Lista* l){
	Lista* p;
	float soma=0;
	int cont=0;
	for (p = l; p != NULL; p = p->prox)
	{
		soma=soma+p->info;
		cont++;
	}
	printf ("\nSomatorio deu %.2f e existem %d elementos na lista\n", soma, cont);
	return soma/cont;
}

int main(){
	Lista* l;
	printf ("\nCriando lista....");
	l = lst_cria();
	printf ("\nInserindo elementos na lista....\n");
	l = lst_insere (l, 1);
	l = lst_insere (l, 5);
	l = lst_insere (l, 2);
	l = lst_insere (l, 3);
	printf ("\nImprimindo lista....\n");
	lst_imprime (l);
	if (l!=NULL)//ha elementos na lista
	{
		printf ("\nCalculando media...");
		float media = lst_calculaMedia (l);
		printf ("\nA media eh %.2f\n", media);
	}
	system("PAUSE");
	return 1;
}