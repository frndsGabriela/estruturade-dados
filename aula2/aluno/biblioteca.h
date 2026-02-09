#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX 50

typedef struct {
    int codigo;
    char titulo[50];
    char autor[50];
} Livro;

typedef struct {
    int id;
    char nome[50];
} Usuario;

typedef struct {
    int idUsuario;
    int codLivro;
    char data[15];
} Emprestimo;

#endif
