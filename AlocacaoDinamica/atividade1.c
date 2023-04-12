// Implemente uma função que indique se um ponto (x,y) está localizado dentro ou fora de um retângulo.
// O retângulo é definido por seus vértices inferior esquerdo (x0,y0) e superior direito (x1,y1). A função
// deve ter como valor de retorno 1, se o ponto estiver dentro do retângulo, e 0 caso contrário, obedecendo
// ao protótipo: int dentro_ret (int x0, int y0, int x1, int y1, int x, int y)

#include <stdio.h>
#include <stdlib.h>

int dentro_ret(int x0, int y0, int x1, int y1, int x, int y);

int main(){
    int x0, y0, x1, y1, x, y, retorno;

    while(1){
        printf("\n\n\nInforme o ponto inferior esquerdo do ret (x,y): ");
        scanf("%d %d", &x0, &y0);
        printf("\nInforme o ponto superior direito do ret (x,y): ");
        scanf("%d %d", &x1, &y1);
        printf("\nInforme o pto a verificar (x,y): ");
        scanf("%d %d", &x, &y);

        retorno = dentro_ret(x0, y0, x1, y1, x, y);
        if (retorno == 1)
        printf("\nPto (%d,%d) ESTA dentro do retangulo [(%d,%d),(%d,%d)]\n", x, y, x0, y0, x1 , y1);

        else
        printf ("\nPto (%d,%d) NAO ESTA dentro do retangulo [(%d,%d),(%d,%d)]\n", x, y, x0, y0, x1, y1);
    }
    return 0;
    system("pause");
}

int dentro_ret(int x0, int y0, int x1, int y1, int x, int y){
    if (x >= x0 && x <= x1 && y >= y0 && y <= y1)
    return 1;

    else
    return 0;
}
