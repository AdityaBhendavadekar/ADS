#include<stdio.h>

void selectionSort(int arr[], int n){
   int mini;
    for(int i=0;i<n-1;i++){
        mini = i;
        for(int j=i;j<n;j++){
            if(arr[mini]>arr[j]){
                mini= j;
            }
        }
        int temp = arr[i];
        arr[i]=arr[mini];
        arr[mini]=temp;
    }
    printf("sorted arrray: ");
    for(int i=0;i<n;i++){
        printf(" %d ", arr[i]);
    }
}

int main(){

    int arr[5]={23,45,67,34,32};
    int n=5;

    selectionSort(arr,5);   

    return 0;
}