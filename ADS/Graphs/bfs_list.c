#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define Ver 5

struct node {
    int vertex;
    struct node* next;
};

struct graph {
    int numVertices;
    struct node** adjLists;
};

struct node* createNode(int v) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->vertex = v;
    n->next = NULL;

    return n;
}

bool isEmpty(int front, int rear) {
    if (front > rear) {
        return true;
    }
    return false;
}

int dequeue(int queue[10], int* front, int* rear) {
    if (*front == -1) {
        printf("Queue underflow\n");
        return -1;
    }

    int deleted = queue[*front];
    (*front)++;
    return deleted;
}

void enqeue(int s, int q[10], int* front, int* rear) {
    if (*rear >= 9) {
        printf("Queue full");
        return;
    }

    if ((*front) == -1 && (*rear) == -1) {
        *front = 0;
        *rear = 0;
    } else {
        (*rear)++;
    }

    q[*rear] = s;
}

void BFS(struct graph* g) {
    int queue[10];
    int front = -1, rear = -1;
    int visited[Ver];
    int start, w;

    for (int i = 0; i < Ver; i++) {
        visited[i] = 0;
    }

    printf("Enter start node: ");
    scanf("%d", &start);

    enqeue(start, queue, &front, &rear);
    visited[start] = 1;

    while (!isEmpty(front, rear)) {
        w = dequeue(queue, &front, &rear);
        printf("%d ", w);

        // Enqueue all adjacent vertices of w in queue.
        struct node* temp = g->adjLists[w];
        while (temp) {
            if (visited[temp->vertex] == 0) {
                enqeue(temp->vertex, queue, &front, &rear);
                visited[temp->vertex] = 1; // Mark the vertex as visited
            }
            temp = temp->next;
        }
    }
}

void printAdjList(struct graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        struct node* temp = g->adjLists[i];
        printf("Vertex %d | ", i);
        while (temp) {
            printf(" %d ->", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void addEdge(struct graph* g, int v, int u) {
    // Add edge from v -> u
    struct node* newNode = createNode(u);
    struct node* temp = g->adjLists[v];
    if (temp == NULL) {
        g->adjLists[v] = newNode;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Add edge from u -> v
    newNode = createNode(v);
    temp = g->adjLists[u];
    if (temp == NULL) {
        g->adjLists[u] = newNode;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct graph* createGraph(int v) {
    struct graph* g = (struct graph*)malloc(sizeof(struct graph));
    g->numVertices = v;
    g->adjLists = (struct node**)malloc(v * sizeof(struct node*));

    for (int i = 0; i < v; i++) {
        g->adjLists[i] = NULL;
    }

    return g;
}

int main() {
    struct graph* gr = createGraph(5);

    addEdge(gr, 0, 1);
    addEdge(gr, 0, 2);
    addEdge(gr, 1, 2);
    addEdge(gr, 1, 3);
    addEdge(gr, 1, 4);
    addEdge(gr, 3, 4);

    printAdjList(gr);

    BFS(gr);

    return 0;
}
