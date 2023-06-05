// Implemente funções para inserir e retirar um elemento de uma lista circular
// encadeada (obtenha informações adicionais sobre listas circulares no livro do Celes cap. 10
// página 148 na 1a. edição ou cap. 14 pág 234 na 2a. edição).

#include <stdio.h>
#include <stdlib.h>

struct lista{
	int info;
	struct lista* prox;
};
typedef struct lista Lista;

void lst_imprime (Lista* l){
	Lista* p = l;
	printf ("\n\nImpressao: ");
	if (p!=NULL)
		do{
			printf ("\t%d", p->info);
			p=p->prox;
		}while (p!=l);
}

Lista* ultimo (Lista* l){
	Lista* p=l;
	if (p!=NULL)
		while (p->prox!=l)
			p=p->prox;
	return p;
}


Lista* lst_insere (Lista* l, int i){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	Lista* ult=ultimo (l);
	novo->info = i;
	if (ult==NULL) //lista vazia
		novo->prox = novo;
	else//lista nao vazia
	{
		novo->prox=l;
		ult->prox=novo;
	}
	return novo;
}

Lista* retira (Lista* l, int v){
	Lista* ant = NULL; //ponteiro para elemento anterior
	Lista* p = l; //ponteiro para percorrer a lista
	//procura elemento na lista, guardando anterior
	Lista* ult = ultimo(l);
	bool achou = false;

	if (p!=NULL) //Se a lista nao for vazia
		if (p->info == v)  //Para o 1o elemento
			achou = true; 
		else  //Para os subsequentes
			do {
				ant = p;
				p = p->prox; 
				if (p->info == v){ 
					achou = true; break;
				}
			} while (p != ult);
     
	if (achou){ //retira elemento
		if (ant == NULL){	//retira elemento do inicio
			if (p == ult) //só tem um elemento na lista
				l = NULL;
			else{ //tem mais elementos na lista
				l = p->prox; 
				ult->prox = l;
			}
	    }
	    else //retira elemento do meio da lista
		   ant->prox = p->prox; 	        
	    free(p);
    } else{
		printf ("\nElemento nao encontrado");
		return l; //não achou: retorna lista original
	} 	
	return l;
}	
	
		
main(){
	Lista* l=NULL;
    lst_imprime (l);		
	l=lst_insere (l, 1);
    lst_imprime (l);	
	l=lst_insere (l, 2);
    lst_imprime (l);	
	l=lst_insere (l, 3);
    lst_imprime (l);	
	l=lst_insere (l, 4);
    lst_imprime (l);
   	l=lst_insere (l, 5);
    lst_imprime (l);	
	l=lst_insere (l, 6);
    lst_imprime (l);	
	l=lst_insere (l, 7);
    lst_imprime (l);	
	l=lst_insere (l, 8);
    lst_imprime (l); 
	int elemento;
	while (1)
	{
		printf ("\nDigite o elemento a retirar: ");
		scanf ("%d", &elemento);
		l =  retira (l, elemento);	
		lst_imprime (l);	
	}	
}