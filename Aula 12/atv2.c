#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void criarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int estaVazia(Fila *f) {
    return f->inicio == NULL;
}

void enqueue(Fila *f, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (estaVazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void exibirFila(Fila *f) {
    No *aux = f->inicio;

    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }

    printf("\n");
}

void inserirPrioridade(Fila *f, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (estaVazia(f) || valor < f->inicio->valor) {
        novo->prox = f->inicio;
        f->inicio = novo;

        if (f->fim == NULL)
            f->fim = novo;

        return;
    }

    No *aux = f->inicio;

    while (aux->prox != NULL && aux->prox->valor < valor) {
        aux = aux->prox;
    }

    novo->prox = aux->prox;
    aux->prox = novo;

    if (novo->prox == NULL) {
        f->fim = novo;
    }
}

void inverterFila(Fila *f) {
    No *ant = NULL;
    No *atual = f->inicio;
    No *prox;

    f->fim = f->inicio;

    while (atual != NULL) {
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }

    f->inicio = ant;
}

Fila copiarFila(Fila *f) {
    Fila nova;
    criarFila(&nova);

    No *aux = f->inicio;

    while (aux != NULL) {
        enqueue(&nova, aux->valor);
        aux = aux->prox;
    }

    return nova;
}

Fila concatenarFilas(Fila *f1, Fila *f2) {
    Fila nova;
    criarFila(&nova);

    No *aux = f1->inicio;

    while (aux != NULL) {
        enqueue(&nova, aux->valor);
        aux = aux->prox;
    }

    aux = f2->inicio;

    while (aux != NULL) {
        enqueue(&nova, aux->valor);
        aux = aux->prox;
    }

    return nova;
}

int main() {
    Fila f1, f2, copia, concat;

    criarFila(&f1);
    criarFila(&f2);

    inserirPrioridade(&f1, 30);
    inserirPrioridade(&f1, 10);
    inserirPrioridade(&f1, 20);

    printf("Fila prioridade: ");
    exibirFila(&f1);

    inverterFila(&f1);
    printf("Fila invertida: ");
    exibirFila(&f1);

    copia = copiarFila(&f1);
    printf("Copia da fila: ");
    exibirFila(&copia);

    enqueue(&f2, 100);
    enqueue(&f2, 200);

    concat = concatenarFilas(&f1, &f2);
    printf("Fila concatenada: ");
    exibirFila(&concat);

    return 0;
}
