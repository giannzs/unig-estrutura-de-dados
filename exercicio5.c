#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Definição da estrutura da lista
typedef struct
{
    int items[MAX_SIZE];
    int size;
} List;

// Função para inicializar a lista
void initList(List *list)
{
    list->size = 0;
}

// Função para verificar se a lista está vazia
int isEmpty(List *list)
{
    return list->size == 0;
}

// Função para verificar se a lista está cheia
int isFull(List *list)
{
    return list->size == MAX_SIZE;
}

// Função para adicionar um elemento à lista no final
void append(List *list, int value)
{
    if (isFull(list))
    {
        printf("List is full.\n");
        return;
    }
    list->items[list->size] = value;
    list->size++;
}

// Função para inserir um elemento em uma posição específica na lista
void insertAt(List *list, int value, int index)
{
    int i;
    if (isFull(list))
    {
        printf("List is full.\n");
        return;
    }
    if (index < 0 || index > list->size)
    {
        printf("Invalid index.\n");
        return;
    }
    for (i = list->size; i > index; i--)
    {
        list->items[i] = list->items[i - 1];
    }
    list->items[index] = value;
    list->size++;
}

// Função para remover um elemento de uma posição específica na lista
void removeFrom(List *list, int index)
{
    int i;
    if (isEmpty(list))
    {
        printf("List is empty.\n");
        return;
    }
    if (index < 0 || index >= list->size)
    {
        printf("Invalid index.\n");
        return;
    }
    for (i = index; i < list->size - 1; i++)
    {
        list->items[i] = list->items[i + 1];
    }
    list->size--;
}

// Função para imprimir a lista
void printList(List *list)
{
    int i;
    printf("List: ");
    for (i = 0; i < list->size; i++)
    {
        printf("%d ", list->items[i]);
    }
    printf("\n");
}

int main()
{
    List list;
    initList(&list);

    // Adicionando elementos à lista
    append(&list, 10);
    append(&list, 20);
    append(&list, 30);

    // Inserindo um elemento na posição 1
    insertAt(&list, 15, 1);

    // Removendo o elemento na posição 2
    removeFrom(&list, 2);

    // Imprimindo a lista
    printList(&list);

    return 0;
}
