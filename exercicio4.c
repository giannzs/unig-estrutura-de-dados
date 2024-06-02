#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Definição da estrutura da fila
typedef struct
{
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Função para inicializar a fila
void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue *q)
{
    return q->front == -1;
}

// Função para verificar se a fila está cheia
int isFull(Queue *q)
{
    return q->rear == MAX_SIZE - 1;
}

// Função para adicionar um elemento à fila
void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Função para remover um elemento da fila
int dequeue(Queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        // Se a fila estiver vazia após a remoção, resete os índices
        q->front = q->rear = -1;
    }
    return item;
}

// Função para obter o elemento na frente da fila
int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->items[q->front];
}

int main()
{
    Queue q;
    initQueue(&q);

    // Adicionando elementos à fila
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    // Removendo um elemento da fila e imprimindo
    printf("Removed from queue: %d\n", dequeue(&q));

    // Imprimindo o elemento na frente da fila
    printf("Front element: %d\n", peek(&q));

    return 0;
}
