#include <stdio.h>
#include <stdlib.h>

// Structs
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Funções
Stack* createStack();
int isEmpty(Stack* stack);
int pop(Stack* stack);
int isEmpty(Queue* queue);
int dequeue(Queue* queue);
void push(Stack* stack, int data);
void enqueue(Queue* queue, int data);
Queue* createQueue();
Queue* pilhaParaFila(Stack* pilha);

int main() {
    Stack* pilha = createStack();
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);

    Queue* fila = pilhaParaFila(pilha);

    printf("Elementos da fila: ");
    while (!isEmpty(fila)) {
        int data = dequeue(fila);
        printf("%d ", data);
    }
    printf("\n");

    return 0;
}

// Funções
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia.\n");
        return -1;
    }

    Node* frontNode = queue->front;
    int data = frontNode->data;
    queue->front = frontNode->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(frontNode);
    return data;
}

Queue* pilhaParaFila(Stack* pilha) {
    Queue* fila = createQueue();

    while (!isEmpty(pilha)) {
        int data = pop(pilha);
        enqueue(fila, data);
    }

    return fila;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("A pilha está vazia.\n");
        return -1;
    }

    Node* topNode = stack->top;
    int data = topNode->data;
    stack->top = topNode->next;

    free(topNode);
    return data;
}
