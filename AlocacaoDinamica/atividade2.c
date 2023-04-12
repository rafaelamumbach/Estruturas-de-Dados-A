#include <stdio.h>
#include <stdlib.h>

int negativos (int n, float *vet);
int le_dimensao (void);
float* aloca_vetor (int n);
void le_vetor(int n, float* vet);

int main(){
    int n, contaNeg;
    float *vet;
    n = le_dimensao();
    vet = aloca_vetor (n);
    le_vetor (n, vet);
    contaNeg = negativos (n, vet);
    printf("\nO numero de negativos neste vetor eh %d\n", contaNeg);
    free(vet);
    system("pause");
}

int le_dimensao (void){
    int tamanho;
    printf("\nInforme o tamanho do vetor: ");
    scanf("%d", &tamanho);
    return tamanho;
}

float* aloca_vetor (int n){
    float* vet = (float*)malloc(n*sizeof(float));
    if (vet == NULL){
        printf("\nMemoria insuficiente.\n");
        system("pause");
        exit(1);
    }
    return vet;
}

void le_vetor (int n, float* vet){
    int i;
    for(i = 0; i < n; i++){
        printf("\nInforme o valor de vet[%d]: ", i);
        scanf("%f", &vet[i]);
    }
}

int negativos (int n, float *vet){
    int contaNeg = 0, i;
    for (i = 0; i < n; i++)
    if (vet[i] < 0)
    contaNeg++;

    return contaNeg;
}
