#include <stdio.h>
#include "aluno.h"

Turma turmas[MAX_TURMAS];
int qtdTurmas = 0;

void cadastrarTurma() {
    Turma t;

    printf("Codigo: ");
    scanf("%d", &t.codigo);

    printf("Nome: ");
    scanf(" %[^\n]", t.nome);

    t.qtdAlunos = 0;

    turmas[qtdTurmas++] = t;
}

void cadastrarAluno() {
    int cod;

    printf("Codigo da turma: ");
    scanf("%d", &cod);

    for(int i=0;i<qtdTurmas;i++){
        if(turmas[i].codigo == cod){

            Aluno a;

            printf("ID: ");
            scanf("%d",&a.id);

            printf("Nome: ");
            scanf(" %[^\n]", a.nome);

            printf("Nota: ");
            scanf("%f",&a.nota);

            turmas[i].alunos[turmas[i].qtdAlunos++] = a;
            return;
        }
    }

    printf("Turma nao encontrada!\n");
}

void listarAlunos() {
    int cod;

    printf("Codigo da turma: ");
    scanf("%d",&cod);

    for(int i=0;i<qtdTurmas;i++){
        if(turmas[i].codigo == cod){

            for(int j=0;j<turmas[i].qtdAlunos;j++){
                printf("%s - %.2f\n",
                       turmas[i].alunos[j].nome,
                       turmas[i].alunos[j].nota);
            }
        }
    }
}

int main() {
    int op;

    do {
        printf("\n1 Cadastrar Turma\n2 Cadastrar Aluno\n3 Listar\n0 Sair\n");
        scanf("%d",&op);

        switch(op){
            case 1: cadastrarTurma(); break;
            case 2: cadastrarAluno(); break;
            case 3: listarAlunos(); break;
        }

    } while(op != 0);
}
