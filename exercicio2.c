#include <stdio.h>

#define MAX_SIZE 50

typedef struct
{
    int dado[MAX_SIZE]; // array de itens da lista
    int n;              // total de elementos da lista
} Lista;

// Função para remover um elemento da lista na posição especificada
void removerElemento(Lista *L, int pos)
{
    if (pos < 1 || pos > L->n)
    {
        printf("Posicao invalida!\n");
        return;
    }

    // Remover elemento movendo os elementos uma posição para trás
    for (int i = pos; i < L->n; i++)
        L->dado[i - 1] = L->dado[i];

    // Atualizar o tamanho da lista
    (L->n)--;
}

int main()
{
    Lista minhaLista = {{1, 2, 3, 4, 5}, 5}; // Exemplo de uma lista inicial

    printf("Lista antes da remocao do elemento na posicao 3:\n");
    for (int i = 0; i < minhaLista.n; i++)
        printf("%d ", minhaLista.dado[i]);
    printf("\n");

    removerElemento(&minhaLista, 3); // Remover o elemento na posição 3

    printf("Lista depois da remocao do elemento na posicao 3:\n");
    for (int i = 0; i < minhaLista.n; i++)
        printf("%d ", minhaLista.dado[i]);
    printf("\n");

    return 0;
}
