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

void dequeue(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia\n");
        return;
    }

    No *temp = f->inicio;
    f->inicio = f->inicio->prox;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);
}

void exibirFila(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia\n");
        return;
    }

    No *aux = f->inicio;

    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }

    printf("\n");
}

int contarElementos(Fila *f) {
    int contador = 0;
    No *aux = f->inicio;

    while (aux != NULL) {
        contador++;
        aux = aux->prox;
    }

    return contador;
}

int primeiroElemento(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia\n");
        return -1;
    }

    return f->inicio->valor;
}

int main() {
    Fila f;

    criarFila(&f);

    enqueue(&f, 10);
    enqueue(&f, 20);
    enqueue(&f, 30);

    printf("Fila: ");
    exibirFila(&f);

    printf("Quantidade: %d\n", contarElementos(&f));

    printf("Primeiro elemento: %d\n", primeiroElemento(&f));

    dequeue(&f);

    printf("Fila apos remover: ");
    exibirFila(&f);

    return 0;
}
