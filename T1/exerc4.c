#include <stdio.h>
#include <stdlib.h>

int ***aloca_matriz(int m, int n, int z);
void preenche_matriz(int m, int n, int z, int ***mat);
void imprime_matriz(int m, int n, int z, int ***mat);

int ***aloca_matriz(int m, int n, int z){
    int i, j;
    int ***mat = (int ***)malloc(m * sizeof(int **));
    for (i = 0; i < m; i++){
        mat[i] = (int **)malloc(n * sizeof(int *));
        for (j = 0; j < n; j++){
            mat[i][j] = (int *)malloc(z * sizeof(int));
        }
    }
    return mat;
}

void preenche_matriz(int m, int n, int z, int ***mat){
    int i, j, k;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            for (k = 0; k < z; k++){
                printf("Informe o valor de mat[%d][%d][%d]: ", i, j, k);
                scanf("%d", &mat[i][j][k]);
            }
        }
    }
}

void imprime_matriz(int m, int n, int z, int ***mat){
    int i, j, k;
    for (i = 0; i < m; i++){
        printf("\n\n");
        printf("Lado [%d] da mat:\n", i + 1);
        for (j = 0; j < n; j++){
            for (k = 0; k < z; k++){
                printf("%d ", mat[i][j][k]);
                printf("\n");
            }
        }
    }
}

int main(){
    int ***mat;
    int m, n, z;
    printf("-- Matriz 3D! --\n\n");
    printf("Informe m, n e z (linhas, colunas e prof.): ");
    scanf("%d %d %d", &m, &n, &z);
    mat = aloca_matriz(m, n, z);
    preenche_matriz(m, n, z, mat);
    imprime_matriz(m, n, z, mat);
    system("pause");
}