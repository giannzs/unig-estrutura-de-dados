#include <stdio.h>
#include <string.h>

typedef struct
{
    long matricula;
    char nome[50];
    int turma;
} aluno;

aluno a1[100];

int main()
{
    // Atribuição de "Joao" à variável nome na posição 1 do vetor a1
    strcpy(a1[1].nome, "Joao");

    // Exemplo de impressão do nome do aluno na posição 1 do vetor a1
    printf("Nome do aluno na posicao 1: %s\n", a1[1].nome);

    return 0;
}
