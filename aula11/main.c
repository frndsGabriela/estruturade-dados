#include <stdio.h>
#include "fila.h"

int main() {
    Fila f;

    inicializarFila(&f);

    inserir(&f, 10);
    inserir(&f, 20);
    inserir(&f, 30);

    printf("Fila atual:\n");
    exibir(&f);

    remover(&f);

    printf("Fila apos remover:\n");
    exibir(&f);

    return 0;
}
