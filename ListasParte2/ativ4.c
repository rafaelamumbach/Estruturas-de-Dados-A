// Implemente uma função que remova o elemento anterior a um elemento de valor v. Esta função deve ter o
// protótipo:
// Lista* lst_retira_ant (Lista* l, int v)
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

//
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

//função retira: retira elemento da lista
Lista* lst_retira (Lista* l, int v){
	Lista* ant = NULL; //ponteiro para elemento anterior
	Lista* p = l; //ponteiro para percorrer a lista
	//procura elemento na lista, guardando anterior

	while (p != NULL && p->info != v){
		ant = p;
		p = p->prox;
	}
	//verifica se achou elemento
	if (p == NULL)
		return l; //não achou: retorna lista original
	//retira elemento
	if (ant == NULL)
		l = p->prox;
	else
		ant->prox = p->prox;
	free(p);
	return l;
}

//função retira: retira elemento anterior da lista
Lista* lst_retira_ant (Lista* l, int v){
	Lista* p = l; //ponteiro para percorrer a lista
	if (p==NULL){ //lista vazia
		printf ("\nREMOCAO FALHOU: Lista vazia... Retornando lista....");
		return l;
	}
	if (p->info==v){ //nao posso remover o anterior ao inicio da lista!
		printf ("\nREMOCAO FALHOU: Querendo remover o anterior ao inicio... Retornando lista....");
		return l;
	}
	while (p!=NULL){ //enquanto nao chegar ao final da lista
		if (p->prox!=NULL) //existe um proximo elemento na lista
			if (p->prox->info==v){ //este proximo eh o valor passado
				printf ("\nVai remover o %d", p->info);
				l=lst_retira(l, p->info); //manda remover o anterior ao valor passado
				return l;
			}
		p=p->prox;
	}
	return l;
}

int main(){
	Lista* l;
	printf ("\nCriando lista....");
	l = lst_cria();
	printf ("\nInserindo elementos na lista....");
	l = lst_insere (l, 50);
	l = lst_insere (l, 40);
	l = lst_insere (l, 30);
	l = lst_insere (l, 20);
	l = lst_insere (l, 10);
	printf ("\nImprimindo lista....\n");
	lst_imprime (l);
	printf ("\nRemovendo elemento anterior...");
	l = lst_retira_ant (l, 10);
	printf ("\nImprimindo lista novamente....\n");
	lst_imprime (l);
	system("PAUSE");
	return 1;
}