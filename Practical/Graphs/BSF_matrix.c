#include<stdio.h>

void BFS(){
    
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
    int n=5;
    int adjMatrix[6][6];
    
    int arr[][2]={{1,2}, {2,3}, {4,5}, {1,5}};
    
    int m = sizeof(arr)/ sizeof(arr[0]);

    createAjMatrix(adjMatrix, arr, n+1,m);
    printf("Adjacency Matrix created");

    showAdjMatrix(adjMatrix, n+1);

    return 0;
}