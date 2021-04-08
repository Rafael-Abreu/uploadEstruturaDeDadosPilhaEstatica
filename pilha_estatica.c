#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 100

typedef struct {
	int Item[MAXTAM];
	int Topo;
} TPilha; // Nome da estrutura por estar definido em typedef

// Função para iniciar a contagem das pilhas
void TPilha_Inicia (TPilha *p ) {
	p->Topo = -1;
}

// Função para verificar se a pilha está vazia
int TPilha_Vazia (TPilha *p) {
	if (p->Topo == -1) {
		return 1;
	} else {
		return 0;
	}
}

// Função para verificar se a pilha está cheia
int TPilha_Cheia (TPilha *p) {
	if (p->Topo == MAXTAM-1) {
		return 1;
	} else {
		return 0;
	}
}

// Criando função de insere/remove
void TPilha_Insere (TPilha *p, int x) {
	if(TPilha_Cheia(p) == 1) {
		printf("ERRO> Pilha cheia");
		fflush(stdout);
	} else {
		p->Topo++;
		p->Item[p->Topo] = x;
	}
}

// Remover/Retirar Item da pilha
int TPilha_Retira (TPilha *p) {
	int aux;
	if(TPilha_Vazia(p) == 1) {
		printf("ERRO: Pilha vazia");
		fflush(stdout);
	} else {
		aux = p->Item[p->Topo];
		p->Topo--;
		return aux;
	}
}

// Testando as funções criadas
int main() {
	TPilha *p = (TPilha*)malloc(sizeof(TPilha));
	TPilha_Inicia(p);

	TPilha_Insere(p, 1);
	TPilha_Insere(p, 2);
	TPilha_Insere(p, 3);

	int aux;

	aux = TPilha_Retira(p);
	printf("\n SAIU: %d", aux);
	fflush(stdout);

	aux = TPilha_Retira(p);
	printf("\n SAIU: %d", aux);
	fflush(stdout);

	aux = TPilha_Retira(p);
	printf("\n SAIU: %d", aux);
	fflush(stdout);
}
