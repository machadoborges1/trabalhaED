#include "funcao.h"

Pilha * criaPilha(){
    Pilha * pi = malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->tamanho = 0;
    }
    return pi;
}

void liberaPilha(Pilha * pi){
    free(pi);
}



Cardapio* criaCardapio() {
    Cardapio* cd;
    cd = (Cardapio*) malloc (sizeof(Cardapio));
    if(cd !=NULL) {
        cd->qtd = 0;
    }
    return cd;
}

PilhaChocolate* criaPilhaChocolate() {
    PilhaChocolate* cd;
    cd =  malloc (sizeof(PilhaChocolate));
    if(cd !=NULL) {
        cd->qtd = 0;
    }
    return cd;
}

void liberaCardapioChocolate(PilhaChocolate* cd) {
    free(cd);
}

void liberaCardapio(Cardapio* cd) {
    free(cd);
}

Comanda* criaComanda() {
    Comanda* cmd;
    cmd = (Comanda*) malloc (sizeof(Comanda));
    if(cmd !=NULL) {
        cmd->qtd = 0;
    }
    return cmd;
}

void liberaComanda(Comanda* cmd) {
    free(cmd);
}

void carregaCardapio(Cardapio *cd) {
    FILE *f = NULL;
    float total = 0;
    f = fopen("cardapio.txt", "r");
    if(!f) {
        printf("Erro na abertura");
    }

    for(int i = 0; i < MAX; i++) {
        fscanf( f, "Id = %d\n", &cd->cardapio[i].id );
        fscanf( f, "Nome = %[^\n]\n", cd->cardapio[i].nome );
        fscanf( f, "Preco = %f\n", &cd->cardapio[i].preco );
        cd->qtd++;
        total += cd->cardapio[i].preco;

    }
    fclose(f);
}

void carregaPilha(PilhaChocolate *pi) {
    FILE *f = NULL;
    float total = 0;
    f = fopen("chocolate.txt", "r");
    if(!f) {
        printf("Erro na abertura");
    }

    for(int i = 0; i < MAX; i++) {
        fscanf( f, "Nome = %[^\n]\n", pi->chocos[i].nome );
        pi->qtd++;
    }
    fclose(f);
}

Fila* criaFila() {
    Fila* fi = (Fila*) malloc (sizeof(Fila));
    if(fi != NULL) {
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void liberaFila(Fila* fi) {
    free(fi);
}


int filaCheia(Fila* fi) {
    if(fi == NULL) return 1;
    if(fi->qtd == MAX)
        return 1;
    else
        return 0;
}

int filaVazia(Fila* fi) {
    if(fi == NULL) return 1;
    if(fi->qtd == 0)
        return 0;
    else 
        return 0;
}

int pilhaCheia(Pilha* pi) {
    if(pi == NULL) return 1;
    if(pi->tamanho == MAX)
        return 1;
    else
        return 0;
}

int pilhaVazia(Pilha * pi){
    if(pi == NULL) return 1;
    if(pi->tamanho == 0) return 1;
    return 0;
}

int removerDaPilha(Pilha * pi){
    if(pilhaVazia(pi) || pi == NULL) return 0;
    pi->tamanho--;
}

void adicionarNaPilha(Pilha * pi, Chocolate ch){
    if(pi == NULL) return;
    if(pilhaCheia(pi)) {
        printf("Pilha cheia\n");
        return;
    }
    pi->chocolate[pi->tamanho] = ch;
    pi->tamanho++;
}



void adicionaNaFila(Fila* fi, Comanda *cmd) {
    if(fi == NULL || cmd == NULL) return;
    if(filaCheia(fi)) {
        printf("Fila cheia nao foi possivel adicionar a comanda\n");
        return;
    }
    fi->comandas[fi->final] = *cmd;
    fi->final++;
    fi->qtd++;
    if(fi->final == MAX) {
        fi->final = 0;
    }
}

int buscaID (Cardapio* cd, int search, Item** it) {
    if(cd == NULL) {
        printf("nulo\n");
        return 0;
        
    }
    int i = 0;
    
    while(i < cd->qtd && cd->cardapio[i].id != search) 
        i++;
    if(i == cd->qtd){ // id não foi encontrado
        printf("Nao encontrado\n");
        return 0;
        
    }
    
    *it = &cd->cardapio[i];
    
    return 1;
}
void geradorDeComandas(Comanda *cmd, Cardapio *cd) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0 ; j < MAX; j++) {

            int id = rand() % 10 + 1;
            Item* it;
            buscaID(cd, id, &it);
            cmd->comanda[i] = *it;
        }
    }
    
}



float calculaTotal(Comanda *cmd) {
	float total = 0;
	for (int i = 0; i < MAX; i++) {
		total += cmd->comanda[i].preco;
	}
	return total;
}