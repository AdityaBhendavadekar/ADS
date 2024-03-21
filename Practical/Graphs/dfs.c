#include <stdio.h>
#include <stdbool.h>

int n = 4;

bool isEmpty(int top){
   if(top<0){
      return true;
   }
   return false;
}

void push(int ele, int stack[10], int *top){
    
    if((*top)>=10){
        printf("Stack overflow");
    }
    (*top)++;
    stack[(*top)]= ele;

}

int pop(int stack[], int *top){
    int ele = stack[(*top)];
     (*top)--;   
    return ele;
}

void DFS(int adjMatrix[6][6], int n){
    int visited[5];
    int w, start;
    int top=0;
    int stack[10];

    printf("Enter start: ");
    scanf("%d", &start);

    for (int  i = 0; i <6; i++){
        visited[i]=0;
    }

    printf(" %d ", start);
    visited[start]=1;
    push(start,stack,&top);
    w=start;

    while(!isEmpty(top)){
        for(int i=0;i<n;){
            if(adjMatrix[w][i]==1 && visited[i]==0){
                push(i,stack,&top);
                printf(" %d ",i);
                visited[i]=1;
                w=i;
            }
            else
                i++;
        }        
        w=pop(stack,&top);
    }
}

void showAdjMatrix(int adjMatrix[6][6], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void createAjMatrix(int adjMatrix[6][6], int arr[][2], int size, int m){
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

int main(){
    int adjMatrix[n + 1][n + 1];
    int arr[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 4}, {3, 4}};
    int m = 6;

    createAjMatrix(adjMatrix, arr, n + 1, m);
    printf("Adjacency Matrix created\n");

    showAdjMatrix(adjMatrix, n + 1);
    DFS(adjMatrix, n + 1);

    return 0;
}