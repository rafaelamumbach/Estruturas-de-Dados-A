#include <stdio.h>
#include <stdlib.h>

struct lista{
    int linha;
    int coluna;
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

struct esparsa{
    int linhas;
    int colunas;
    struct lista *prim;
};
typedef struct esparsa Esparsa;

void calcularPercentual(Esparsa *esparsa){
    Lista *atual = esparsa->prim;
    int totalElementos = 0;
    int elementosNaoZero = 0;

    for (int i = 0; i < esparsa->linhas; i++){
        for (int j = 0; j < esparsa->colunas; j++){
            totalElementos++;
        }
    }

    while (atual != NULL){
        if (atual->info != 0){
            elementosNaoZero++;
        }
        atual = atual->prox;
    }

    float percentual = 0.0;

    if (totalElementos > 0){
        percentual = (float)elementosNaoZero / totalElementos * 100.0 * 10.0;
    }

    printf("\nPercentual de elementos nao nulos: %.2f\n", percentual);
}

void somarLinha(Esparsa *esparsa){
    int linha, soma = 0;
    Lista *atual = esparsa->prim;
    printf("\nInforme a linha a somar");
    scanf("%i", &linha);
    while (atual != NULL){
        if (atual->linha == linha){
            soma += atual->info;
        }
        atual = atual->prox;
    }
    printf("\nSoma da linha=:\n%i", soma);
}

void imprimirElemento(Esparsa *esparsa){
    int linha, coluna;
    printf("\nInforme a linha do elemento a mostrar");
    scanf("%i", &linha);
    printf("\nInforme a coluna do elemento a mostrar");
    scanf("%i", &coluna);
    Lista *atual = esparsa->prim;
    int encontrado = 0;

    while (atual != NULL){
        if (atual->linha == linha && atual->coluna == coluna){
            printf("Elemento na posicao (%d, %d): %d\n", linha, coluna, atual->info);
            encontrado = 1;
            break;
        }
        atual = atual->prox;
    }

    if (!encontrado){
        printf("Elemento na posicao (%d, %d): 0\n", linha, coluna);
    }
}

Esparsa *criarEsparsa(){
    Esparsa *esparsa = (Esparsa *)malloc(sizeof(Esparsa));
    esparsa->prim = NULL;
    return esparsa;
}

void inserirElemento(Esparsa *esparsa, int linha, int coluna, int info){
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->linha = linha;
    novo->coluna = coluna;
    novo->info = info;
    novo->prox = NULL;

    if (esparsa->prim == NULL){
        esparsa->prim = novo;
    }
    else{
        Lista *atual = esparsa->prim;
        Lista *anterior = NULL;

        while (atual != NULL && (atual->linha < linha || (atual->linha == linha && atual->coluna < coluna))){
            anterior = atual;
            atual = atual->prox;
        }

        if (anterior == NULL){
            novo->prox = esparsa->prim;
            esparsa->prim = novo;
        }
        else{
            anterior->prox = novo;
            novo->prox = atual;
        }
    }
}

void exibirEsparsa(Esparsa *esparsa){
    int linhas = esparsa->linhas;
    int colunas = esparsa->colunas;

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            Lista *atual = esparsa->prim;
            int hasData = 0;

            while (atual != NULL){
                if (atual->linha == i && atual->coluna == j){
                    printf("%d ", atual->info);
                    hasData = 1;
                    break;
                }
                atual = atual->prox;
            }

            if (!hasData){
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(){
    Esparsa *esparsa = criarEsparsa();
    int linha, coluna, info;
    int linhas = 0, colunas = 0;

    while (1){
        printf("Informe a linha do novo elemento a inserir (-1 para parar de inserir): ");
        scanf("%d", &linha);

        if (linha == -1)
            break;

        printf("Informe a coluna do novo elemento a ser inserido: ");
        scanf("%d", &coluna);
        printf("Informe o novo elemento a ser inserido: ");
        scanf("%d", &info);

        if (linha >= linhas)
            linhas = linha + 1;
        if (coluna >= colunas)
            colunas = coluna + 1;

        inserirElemento(esparsa, linha, coluna, info);
    }

    esparsa->linhas = linhas;
    esparsa->colunas = colunas;

    exibirEsparsa(esparsa);
    imprimirElemento(esparsa);
    somarLinha(esparsa);
    calcularPercentual(esparsa);
    return 0;
}