#include <stdio.h>
#include "vendas.h"

Produto produtos[MAX];
Cliente clientes[MAX];

int qtdProdutos=0, qtdClientes=0;

void cadastrarProduto(){
    printf("Codigo: ");
    scanf("%d",&produtos[qtdProdutos].codigo);

    printf("Nome: ");
    scanf(" %[^\n]",produtos[qtdProdutos].nome);

    printf("Preco: ");
    scanf("%f",&produtos[qtdProdutos].preco);

    qtdProdutos++;
}

void cadastrarCliente(){
    printf("ID: ");
    scanf("%d",&clientes[qtdClientes].id);

    printf("Nome: ");
    scanf(" %[^\n]",clientes[qtdClientes].nome);

    qtdClientes++;
}

void criarVenda(){
    int id, cod;
    float total=0;

    printf("ID cliente: ");
    scanf("%d",&id);

    printf("Quantos produtos? ");
    int q;
    scanf("%d",&q);

    for(int i=0;i<q;i++){
        printf("Codigo produto: ");
        scanf("%d",&cod);

        for(int j=0;j<qtdProdutos;j++){
            if(produtos[j].codigo==cod){
                total += produtos[j].preco;
            }
        }
    }

    printf("Total = %.2f\n", total);
}

int main(){
    int op;

    do{
        printf("\n1 Produto\n2 Cliente\n3 Venda\n0 Sair\n");
        scanf("%d",&op);

        switch(op){
            case 1: cadastrarProduto(); break;
            case 2: cadastrarCliente(); break;
            case 3: criarVenda(); break;
        }

    }while(op!=0);
}
