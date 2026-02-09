#ifndef ALUNO_H
#define ALUNO_H

#define MAX_ALUNOS 50
#define MAX_TURMAS 10

typedef struct {
    int id;
    char nome[50];
    float nota;
} Aluno;

typedef struct {
    int codigo;
    char nome[50];
    int qtdAlunos;
    Aluno alunos[MAX_ALUNOS];
} Turma;

#endif
