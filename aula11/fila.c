#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int filaVazia(Fila *f) {
    return (f->inicio == NULL);
}

void inserir(Fila *f, int valor) {
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));

    if (novo == NULL) {
        printf("Erro de memoria\n");
        return;
    }

    novo->num = valor;
    novo->prox = NULL;

    if (filaVazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void remover(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia\n");
        return;
    }

    Elemento *temp = f->inicio;
    f->inicio = f->inicio->prox;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);
}

void exibir(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia\n");
        return;
    }

    Elemento *aux = f->inicio;

    while (aux != NULL) {
        printf("%d ", aux->num);
        aux = aux->prox;
    }

    printf("\n");
}
