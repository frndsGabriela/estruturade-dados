#ifndef VENDAS_H
#define VENDAS_H

#define MAX 50

typedef struct{
    int codigo;
    char nome[50];
    float preco;
} Produto;

typedef struct{
    int id;
    char nome[50];
} Cliente;

typedef struct{
    Cliente cliente;
    Produto produtos[20];
    int qtd;
    float total;
} Venda;

#endif
