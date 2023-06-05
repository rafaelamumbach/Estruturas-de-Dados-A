// Considere listas que armazenam cadeias de caracteres e implemente uma função para criar uma
// cópia de uma lista encadeada. Essa função deve obedecer ao protótipo: Lista* copia (Lista* l);

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

Lista* inverte(Lista* l){
	Lista* p;
	Lista* pos; // posterior
	Lista* ant; // anterior
	Lista* aux;p = l;
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

Lista* copia (Lista* l){
	Lista *p = l;
	Lista *copia = NULL;
	while (p != NULL) {
		copia = lst_insere (copia, p->info);
		p = p->prox; 
	}
	copia=inverte(copia);
return copia;
}

int main(){
	Lista* l; //declara uma lista não iniciada
	l = lst_cria(); //inicia lista vazia
	l = lst_insere(l, 1);
	l = lst_insere(l, 2);
	l = lst_insere(l, 12);
	l = lst_insere(l, 22);
	Lista* l2=lst_cria();
	l2 = copia(l);
	printf ("\nLista Original: \n");
	lst_imprime (l);
	printf ("\nLista Copia: \n");
	lst_imprime (l2);
	system("pause");
	return 1;
}