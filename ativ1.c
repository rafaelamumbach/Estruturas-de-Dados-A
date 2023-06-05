// Implemente uma função que altere uma lista, de forma que os valores positivos fiquem negativos e os
// negativos fiquem positivos. Esta função deve ter o protótipo:
// Lista* lst_altera (Lista* l);
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

Lista* lst_altera (Lista* l){
	Lista* p;
	for (p = l; p != NULL; p = p->prox)
		p->info=-p->info;
	return l;
}

int main(){
	Lista* l;
	printf ("\nCriando lista....");
	l = lst_cria();
	printf ("\nInserindo elementos na lista....");
	l = lst_insere (l, 50);
	l = lst_insere (l, -40);
	l = lst_insere (l, 30);
	l = lst_insere (l, -20);
	l = lst_insere (l, 10);
	printf ("\nImprimindo lista....\n");
	lst_imprime (l);
	printf ("\nAlterando sinal da lista...");
	l = lst_altera (l);
	printf ("\nImprimindo lista novamente....\n");
	lst_imprime (l);
	lst_libera (l);
	system("PAUSE");
	return 1;
}