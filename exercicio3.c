#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Definição da estrutura da pilha
typedef struct
{
    int items[MAX_SIZE];
    int top;
} Stack;

// Função para inicializar a pilha
void initialize(Stack *s)
{
    s->top = -1; // Pilha vazia
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack *s)
{
    return (s->top == -1);
}

// Função para verificar se a pilha está cheia
int isFull(Stack *s)
{
    return (s->top == MAX_SIZE - 1);
}

// Função para adicionar um elemento (push) à pilha
void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Erro: Pilha cheia, impossível inserir.\n");
        return;
    }
    s->top++;
    s->items[s->top] = value;
    printf("Elemento %d inserido com sucesso.\n", value);
}

// Função principal
int main()
{
    Stack stack;        // Declaração de uma pilha
    initialize(&stack); // Inicializa a pilha

    // Adiciona alguns elementos à pilha
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    return 0;
}
