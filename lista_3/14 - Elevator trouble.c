#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int floor;
    int buttonPresses;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Node* createNode(int floor, int buttonPresses) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->floor = floor;
    newNode->buttonPresses = buttonPresses;
    newNode->next = NULL;
    return newNode;
}

void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

void enqueue(Queue* queue, int floor, int buttonPresses) {
    Node* newNode = createNode(floor, buttonPresses);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

Node* dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return NULL; // Fila vazia
    }

    Node* frontNode = queue->front;
    queue->front = frontNode->next;

    if (queue->front == NULL) {
        queue->rear = NULL; // A fila está vazia após a remoção
    }

    return frontNode;
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

int minButtonPresses(int f, int s, int g, int u, int d) {
    Queue queue;
    initQueue(&queue);

    int* visited = (int*)calloc(f + 1, sizeof(int));

    enqueue(&queue, s, 0);
    visited[s] = 1;

    while (!isEmpty(&queue)) {
        Node* current = dequeue(&queue);

        if (current->floor == g) {
            int result = current->buttonPresses;
            free(current);
            free(visited);
            return result;
        }

        if (current->floor + u <= f && !visited[current->floor + u]) {
            enqueue(&queue, current->floor + u, current->buttonPresses + 1);
            visited[current->floor + u] = 1;
        }

        if (current->floor - d >= 1 && !visited[current->floor - d]) {
            enqueue(&queue, current->floor - d, current->buttonPresses + 1);
            visited[current->floor - d] = 1;
        }

        free(current);
    }

    free(visited);

    return -1;
}

int main() {
    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    int result = minButtonPresses(f, s, g, u, d);

    if (result == -1) {
        printf("use the stairs\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}
