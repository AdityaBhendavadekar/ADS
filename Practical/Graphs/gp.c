#include<stdio.h>
#include<stdbool.h>

bool isEmpty(int front){
    return front == -1;
}

int dequeue(int queue[10], int *front, int *rear){
    int deleted = queue[(*front)++];
    return deleted; 
}

void enqueue(int v, int queue[10], int *front, int *rear){
   
    if(*rear >= 9){
        printf("Queue overflow");
        return;
    }
   
    if(*front == -1 && *rear == -1){
        *front = 0;
        *rear = 0;
    }

    queue[(*rear)++] = v;
}

void BFS(int n, int adjMatrix[6][6]){
    int visited[6];
    int queue[10];
    int start, w;
    int front = -1, rear = -1;

    printf("Enter start: ");
    scanf("%d", &start);

    // setting visited to 0
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    
    // updating visited, queue
    visited[start] = 1;
    enqueue(start, queue, &front, &rear);

    while (!isEmpty(front))
    {
        w = dequeue(queue, &front, &rear);
        printf("%d ", w);

        for(int i = 0; i < n; i++){
            if(adjMatrix[w][i] == 1 && visited[i] == 0){
                enqueue(i, queue, &front, &rear);
                visited[i] = 1;
            }
        }
    }
}

void showAdjMatrix(int adjMatrix[6][6], int n){
    printf("Adjacency matrix is:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void createAdjMatrix(int adjMatrix[6][6], int arr[][2], int size, int m){

    // setting adjacency matrix to 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            adjMatrix[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++){
        int x = arr[i][0];
        int y = arr[i][1];
        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1;
    }
}

int main(){
    int n = 6; // Adjusted size to fit the matrix
    int adjMatrix[6][6];
    
    int arr[][2] = {{1,2}, {2,3}, {4,5}, {1,5}};
    
    int m = sizeof(arr) / sizeof(arr[0]);

    createAdjMatrix(adjMatrix, arr, n, m);
    printf("Adjacency Matrix created\n");

    showAdjMatrix(adjMatrix, n);

    printf("BFS Traversal: \n");
    BFS(n, adjMatrix);

    return 0;
}
