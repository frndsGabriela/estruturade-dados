#include <stdio.h>
#include "biblioteca.h"

Livro livros[MAX];
Usuario usuarios[MAX];
Emprestimo emprestimos[MAX];

int qtdLivros=0, qtdUsuarios=0, qtdEmprestimos=0;

void cadastrarLivro(){
    printf("Codigo: ");
    scanf("%d",&livros[qtdLivros].codigo);

    printf("Titulo: ");
    scanf(" %[^\n]",livros[qtdLivros].titulo);

    printf("Autor: ");
    scanf(" %[^\n]",livros[qtdLivros].autor);

    qtdLivros++;
}

void cadastrarUsuario(){
    printf("ID: ");
    scanf("%d",&usuarios[qtdUsuarios].id);

    printf("Nome: ");
    scanf(" %[^\n]",usuarios[qtdUsuarios].nome);

    qtdUsuarios++;
}

void emprestar(){
    printf("ID usuario: ");
    scanf("%d",&emprestimos[qtdEmprestimos].idUsuario);

    printf("Codigo livro: ");
    scanf("%d",&emprestimos[qtdEmprestimos].codLivro);

    printf("Data: ");
    scanf(" %[^\n]",emprestimos[qtdEmprestimos].data);

    qtdEmprestimos++;
}

int main(){
    int op;

    do{
        printf("\n1 Livro\n2 Usuario\n3 Emprestimo\n0 Sair\n");
        scanf("%d",&op);

        switch(op){
            case 1: cadastrarLivro(); break;
            case 2: cadastrarUsuario(); break;
            case 3: emprestar(); break;
        }

    }while(op!=0);
}
