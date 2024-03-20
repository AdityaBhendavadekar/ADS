#include <stdio.h>
#include <stdbool.h>

int n = 4;

bool isEmpty(int front, int rear)
{
    if (front >= rear)
    {
        return false;
    }
    return true;
}

int dequeue(int queue[10], int *front, int *rear)
{

    if (*front == -1){
        printf("Queue underflow\n");
        return -1;
    }

    int deleted = queue[*front];
    (*front)++;
    return deleted;
}

void enqueue(int v, int queue[10], int *front, int *rear)
{
    if (*front == -1 && *rear == -1){
        *front = 0;
        *rear = 0;
    }

    queue[*rear] = v;
    (*rear)++;
}

void BFS(int adjMatrix[6][6], int n)
{
    int visited[6], start, w;
    int queue[10];
    int front = -1, rear = -1;
    printf("Enter start node: ");
    scanf("%d", &start);

    for (int i = 0; i < n; i++){
        visited[i] = 0;
    }
    enqueue(start, queue, &front, &rear);
    visited[start] = 1;

    while (isEmpty(front, rear))
    {
        w = dequeue(queue, &front, &rear);
        printf(" %d ", w);

        for (int i = 0; i < n; i++)
        {
            if (adjMatrix[w][i] == 1 && visited[i] == 0)
            {
                enqueue(i, queue, &front, &rear);
                visited[i] = 1;
            }
        }
    }
}

void showAdjMatrix(int adjMatrix[6][6], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void createAjMatrix(int adjMatrix[6][6], int arr[][2], int size, int m)
{
    // setting adjacency matrix to 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x = arr[i][0];
        int y = arr[i][1];
        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1;
    }
}

int main()
{

    int adjMatrix[n + 1][n + 1];
    int arr[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 4}, {3, 4}};
    int m = 6;

    createAjMatrix(adjMatrix, arr, n + 1, m);
    printf("Adjacency Matrix created\n");

    showAdjMatrix(adjMatrix, n + 1);
    BFS(adjMatrix, n + 1);

    return 0;
}