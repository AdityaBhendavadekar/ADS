#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int n = 4;

struct Node {
    int vertex;
    struct Node* next;
};

bool isEmpty(int front, int rear) {
    if (front >= rear) {
        return true;
    }
    return false;
}

struct Node* dequeue(struct Node** queue, int* front) {
    if (*front == -1) {
        printf("Queue underflow\n");
        return NULL;
    }

    struct Node* deleted = queue[*front];
    (*front)++;
    return deleted;
}

void enqueue(struct Node** queue, int v, int* front, int* rear) {
    if (*front == -1 && *rear == -1) {
        *front = 0;
        *rear = 0;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;

    queue[*rear] = newNode;
    (*rear)++;
}

void BFS(struct Node** adjList, int n) {
    int visited[6], start, w;
    struct Node* queue[10];
    int front = -1, rear = -1;
    printf("Enter start node: ");
    scanf("%d", &start);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    enqueue(queue, start, &front, &rear);
    visited[start] = 1;

    while (!isEmpty(front, rear)) {
        struct Node* temp = dequeue(queue, &front);
        w = temp->vertex;
        printf(" %d ", w);

        struct Node* current = adjList[w];
        while (current != NULL) {
            if (visited[current->vertex] == 0) {
                enqueue(queue, current->vertex, &front, &rear);
                visited[current->vertex] = 1;
            }
            current = current->next;
        }
    }
}

void showAdjList(struct Node** adjList, int n) {
    for (int i = 0; i < n; i++) {
        struct Node* temp = adjList[i];
        printf("Adjacency list of vertex %d\n", i);
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void createAdjList(struct Node** adjList, int arr[][2], int size, int m) {
    for (int i = 0; i < size; i++) {
        adjList[i] = NULL;
    }

    for (int i = 0; i < m; i++) {
        int x = arr[i][0];
        int y = arr[i][1];

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->vertex = y;
        newNode->next = adjList[x];
        adjList[x] = newNode;

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->vertex = x;
        newNode->next = adjList[y];
        adjList[y] = newNode;
    }
}

int main() {
    struct Node* adjList[n + 1];
    int arr[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 4}, {3, 4}};
    int m = 6;

    createAdjList(adjList, arr, n + 1, m);
    printf("Adjacency List created\n");

    showAdjList(adjList, n + 1);
    BFS(adjList, n + 1);

    return 0;
}