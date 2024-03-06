#include<stdio.h>
#include<stdbool.h>

    int n=5;


bool isEmpty(int rear, int front){
    // if(front>rear){
    //     return true;
    // }
    // return false;
    return front==-1;
}

int dequeue(int queue[10], int *front, int *rear){
    
     if (*front == -1) {
        printf("Queue underflow\n");
        return -1;
    }
    
    int deleted = queue[(*front)++];
    return deleted; 
}

void enqueue(int v,int queue[10], int *front, int *rear){
   
   if(*rear >= 9){
    printf("Queue overflow");
    return;
   }
   
    if(*front==-1 && *rear==-1){
        *front = 0;
        *rear = 0;
    }

    queue[(*rear)++] = v;
}

void BFS(int n, int adjMatrix[6][6]){
    int visited[6];
    int queue[10];
    int start, w;
    int front=-1, rear=-1;

    printf("Enter start: ");
    scanf("%d", &start);

    // setting visited to 0
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    
    // updating visited, queue
    visited[start] = 1;
    enqueue(start, queue, &front, &rear);

    // printf("Front: %d  %d", front, rear);
    // exit(0);

    while (!isEmpty(rear, front))
    {
        w = dequeue(queue, &front, &rear);
        printf("%d ", w);

        for(int i=0;i<n;i++){
            if(adjMatrix[w][i] == 1 && visited[i] == 0){
                enqueue(i, queue, &front, &rear);
                visited[i]=1;
            }
        }
    }
}

void showAdjMatrix(int adjMatrix[6][6], int n){
    printf("Adjacency matrix is:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void createAjMatrix(int adjMatrix[6][6], int arr[][2], int size, int m){

    // setting adjacency matrix to 0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            adjMatrix[i][j]=0;
        }
    }

    for(int i=0;i<m;i++){
        int x = arr[i][0];
        int y = arr[i][1];
        adjMatrix[x][y]=1;
        adjMatrix[y][x]=1;
    }
}

int main(){

    int adjMatrix[n+1][n+1];
    
    int arr[][2]={{1,2}, {2,3}, {4,5}, {1,5}};
    
    int m = sizeof(arr)/ sizeof(arr[0]);

    createAjMatrix(adjMatrix, arr, n+1,m);
    printf("Adjacency Matrix created");

    showAdjMatrix(adjMatrix, n+1);

    printf("BFS Traversal: \n");
    BFS(n, adjMatrix);

    return 0;
}