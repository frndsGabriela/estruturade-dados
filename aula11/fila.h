#ifndef FILA_H
#define FILA_H

typedef struct Elemento {
    int num;
    struct Elemento *prox;
} Elemento;

typedef struct {
    Elemento *inicio;
    Elemento *fim;
} Fila;

void inicializarFila(Fila *f);
int filaVazia(Fila *f);
void inserir(Fila *f, int valor);
void remover(Fila *f);
void exibir(Fila *f);

#endif
