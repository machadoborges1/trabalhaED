#ifndef FUNCAO_H_INCLUDED
#define FUNCAO_H_INCLUDED


#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct chocolate{
    char nome[50];
} Chocolate;

typedef struct item {
    int id;
    char nome[50];
    float preco;
}Item;

typedef struct cardapio {
    int qtd;
    Item cardapio[MAX]; 

}Cardapio;

typedef struct pilhachocolate {
    int qtd;
    Chocolate chocos[MAX]; 
}PilhaChocolate;

typedef struct comanda {
    int qtd;
    Item comanda[MAX];
    float total;
}Comanda;

typedef struct fila {
    int inicio, final,qtd;
    Comanda comandas[MAX];

}Fila;

typedef struct pilha {
    Chocolate chocolate[MAX];
    int tamanho;
} Pilha;


Pilha* criaPilha();
void liberaPilha(Pilha * pi);
int pilhaCheia(Pilha* pi);
void adicionarNaPilha(Pilha * pi, Chocolate ch);
int pilhaVazia(Pilha * pi);
int removerDaPilha(Pilha * pi);
Cardapio* criaCardapio() ;
void liberaCardapio(Cardapio* cd);
void liberaComanda(Comanda* cmd) ;
void carregaCardapio(Cardapio *cd) ;
Fila* criaFila() ;
void liberaFila(Fila* fi) ;
int filaCheia(Fila* fi);
int filaVazia(Fila* fi) ;
void adicionaNaFila(Fila* fi, Comanda *cmd) ;
int buscaID (Cardapio* cd, int search, Item** it) ;
void geradorDeComandas(Comanda *cmd, Cardapio *cd);
float calculaTotal(Comanda *cmd) ;

PilhaChocolate* criaPilhaChocolate();
void carregaPilha(PilhaChocolate *pi);
void liberaCardapioChocolate(PilhaChocolate* cd);

#endif