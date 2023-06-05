// Considere listas de valores inteiros e implemente uma função que receba como parâmetros uma
// lista encadeada e um valor inteiro n, retire da lista todas as ocorrências de n e retorne a lista
// resultante. Esta função deve obedecer ao protótipo: Lista* retira_n (Lista* l, int n);

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
		printf("info = %d\n", p->info);
}

//função retira recursiva
Lista* retira_n (Lista* l, int n){
	if (l!=NULL) {
	//verifica se elemento a ser retirado é o primeiro
		if (l->info == n){
			Lista* t = l; //temporário para poder liberar
			l = l->prox;
			free(t);
			l = retira_n(l,n);
		}
		else{
			//retira de sub-lista
			l->prox = retira_n(l->prox,n);
		}
	}
	return l;
}

int main (void){
	Lista* l; //declara uma lista não iniciada
	int n=2;
	l = lst_cria(); //inicia lista vazia
	l = lst_insere(l, 1);
	l = lst_insere(l, 2);
	l = lst_insere(l, 3);
	l = lst_insere(l, 2);
	l = lst_insere(l, 6);
	l = lst_insere(l, 2);
	l = lst_insere(l, 3);
	l = lst_insere(l, 2);
	l = lst_insere(l, 4);
	l = lst_insere(l, 5);
	l = lst_insere(l, 3);
	l = lst_insere(l, 2);		
	lst_imprime(l);
	printf ("Lista sem ocorrencias de 2\n");
	l = retira_n(l,n);
	lst_imprime(l);
	system("pause");
	return 0;
}