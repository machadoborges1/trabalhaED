#include <stdio.h>
#include <stdlib.h>

#include "funcao.h"
#include "funcao.c"

int main() {
    
    Fila *fi;
    fi = criaFila();

    Cardapio* cd;
    cd = criaCardapio();
    carregaCardapio(cd);

    PilhaChocolate* cdc;
    cdc = criaPilhaChocolate();
    carregaPilha(cdc);
    
    Comanda* cmd;
    cmd = criaComanda();

    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        
        geradorDeComandas(cmd, cd);
        adicionaNaFila(fi, cmd);
    }
    
    Pilha * pi = criaPilha();
    int x = pilhaCheia(pi);
    int y = pilhaVazia(pi);


    for (int i = 0; i < fi->qtd; i++) {
        printf("===============Comanda %d=============\n", i + 1);
        for (int j = 0; j < MAX; j++) {
            printf( "Id = %d\n", fi->comandas[i].comanda[j].id );
            printf( "Nome = %s\n", fi->comandas[i].comanda[j].nome );
            printf( "Preco = R$%.2f\n", fi->comandas[i].comanda[j].preco );
            
        }
        float total = calculaTotal(&fi->comandas[i]);
        printf("total = %.2f\n", total);
    }

    

    printf("%d , %d\n\n\n\n\n", x, y);
    printf( "Nome0000000000000000000 = %s\n", cdc->chocos[9].nome);

    liberaCardapio(cd);
    liberaFila(fi);
}