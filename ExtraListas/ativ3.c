// Implemente uma função que construa uma nova lista com a intercalação dos nós de outras duas
// listas passadas como parâmetros. Esta função deve retornar a lista resultante, conforme
// ilustrado a seguir:
// Esta função deve obedecer ao protótipo: Lista* merge (Lista* l1, Lista* l2);

#include <stdio.h>
#include <stdlib.h>

struct Lista{
   int info;
   struct Lista* prox;
};
typedef struct lista Lista;

Lista* criar(void);
Lista* inserirInicio(Lista* lista, int elemento);
Lista* inserirFim(Lista* lista, int elemento);
void imprimir(Lista* lista);
bool vazia(Lista* lista);
Lista* liberar(Lista* lista);

Lista* criar(void){
   return NULL;
}

bool vazia(Lista* lista){
     return (lista == NULL);
}

Lista* ultimo(Lista* lista){ 
   if (vazia(lista))
      return lista;
   Lista* ultimo = lista;
   while (ultimo->prox != NULL)
      ultimo = ultimo->prox;
   return ultimo;       
}

Lista* inserirInicio(Lista* lista, int elemento){
   Lista* novoNo = (Lista*) malloc(sizeof(Lista));
   novoNo->info = elemento;
   novoNo->prox = lista;
   return novoNo;
}

Lista* inserirFim(Lista* lista, int elemento){
   if (vazia(lista))
      return inserirInicio(lista, elemento);
   ultimo(lista)->prox = inserirInicio(NULL, elemento);
   return lista;
}

void imprimir(Lista* lista){
   if (vazia(lista))
      printf("Lista vazia");
   else {
      int i = 1; 
      Lista* temp = lista;
      while (!vazia(temp)){
         printf("%d: %d\n", i++, temp->info);
         temp = temp->prox;
      }
   }
}


Lista* liberar(Lista* lista){
   while(!vazia(lista)){
      Lista* temp = lista->prox;   //guarda referencia p/ proximo elemento
      free(lista);                 //libera a memoria apontada por p
      lista = temp;                //faz p apontar para o proximo
   }
   return NULL;
}


Lista* merge(Lista* l1, Lista* l2){
	Lista* resultante = criar();
	Lista* tl1 = l1;
	Lista* tl2 = l2;
	while (!(vazia(tl1) && vazia(tl2))){
   	   if (!vazia(tl1)){
	    	resultante = inserirFim(resultante, tl1->info);
		    tl1 = tl1->prox;
		}
		if (!vazia(tl2)){
			resultante = inserirFim(resultante, tl2->info);
			tl2 = tl2->prox;
		}
	}
	return resultante;
}

int main(){
    printf("Lista 1\n");
	Lista* l1 = criar();
    l1 = inserirInicio(l1, 40);
    l1 = inserirInicio(l1, 30);
    l1 = inserirInicio(l1, 20);
    l1 = inserirInicio(l1, 10);
    imprimir(l1);
    
    
    printf("Lista 2\n");
    Lista* l2 = criar();
    l2 = inserirInicio(l2, 41);
    l2 = inserirInicio(l2, 51);
    l2 = inserirInicio(l2, 61);
    imprimir(l2);
    
    printf("Lista 3\n");
    Lista* l3 = merge(l1, l2);
    imprimir(l3);
    
    getchar();
}