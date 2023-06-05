// Implemente uma função que remova o elemento anterior a um elemento de valor v. Esta função deve
// ter o protótipo:
// Lista2* lst_retira_ant (Lista2* l, int v)
// Para testar esta função, use/implemente as funções de:
// - criação de lista
// - inserção na lista
// - impressão da lista

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

//função busca: busca um elemento na lista
Lista2* lst_busca (Lista2* l, int v){
	Lista2* p;
	for (p=l; p!=NULL; p=p->prox)
		if (p->info == v)
			return p;
	return NULL; //não achou o elemento
}

//inserção no início: retorna a lista atualizada
Lista2* lst_insere (Lista2* l, int v){
	Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
	novo->info = v;
	novo->prox = l;
	novo->ant = NULL;
	//verifica se lista não estava vazia
	if (l != NULL)
		l->ant = novo;
	return novo;
}

//função imprime: imprime valores dos elementos
void lst_imprime (Lista2* l){
	Lista2* p;
	for (p = l; p != NULL; p = p->prox)
		printf("\tinfo = %d\n", p->info);
}

Lista2* lst_retira (Lista2* l, int v){
	Lista2* p = lst_busca(l,v);
	if (p == NULL)
		return l; //não achou o elemento: retorna lista inalterada
	//retira elemento do encadeamento
	if (l == p) //testa se é o primeiro elemento
		l = p->prox;
	else
		p->ant->prox = p->prox;
	if (p->prox != NULL) //testa se é o último elemento
		p->prox->ant = p->ant;
	free(p);
	return l;
}

//função retira: retira elemento anterior da lista
Lista2* lst_retira_ant (Lista2* l, int v){
	Lista2* p = l; //ponteiro para percorrer a lista
	if (p==NULL){ //lista vazia
		printf ("\nLista vazia... Retornando lista....");
		return l;
	}
	else { //lista nao vazia
		if (p->info==v){
			printf ("\nQuerendo remover o anterior ao inicio... Retornando lista....");
			return l;
		}
	while (p!=NULL){
	if (p->prox!=NULL)
		if (p->prox->info==v){
			printf ("\nVai remover o %d", p->info);
			l=lst_retira(l, p->info); //chama a funcao que remove um nó da lista
			return l;
		}
		p=p->prox;
	}
	return l;
	} //else
}

int main(){
	Lista2* l;
	printf ("\nCriando lista....");
	l = lst_cria();
	printf ("\nInserindo elementos na lista....");
	l = lst_insere (l, 50);
	l = lst_insere (l, 40);
	l = lst_insere (l, 30);
	l = lst_insere (l, 20);
	l = lst_insere (l, 10);
	while (1)
	{
		printf ("\nImprimindo lista original....\n");
		lst_imprime (l);
		int x;
		printf ("\nInforme o valor: ");
		scanf ("%d", &x);
		printf ("\nRemovendo elemento anterior ao elemento %d: ", x);
		l = lst_retira_ant (l, x);
		printf ("\nImprimindo lista novamente apos a remocao (se ocorreu)....\n");
		lst_imprime (l);
	} //while
	system("PAUSE");
	return 1;
}