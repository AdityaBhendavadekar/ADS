#include<stdio.h>

void insertionSort(int arr[], int size){
    
    for(int i=0;i<size;i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            printf("%d %d < %d ",j, arr[j], arr[j-1]);

            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1]=temp;
            j--;
        }
        printf("\n");
    }
    
    printf("Sorted array: ");
    for(int i=0;i<size;i++){
        printf(" %d ",arr[i]);
    }
}

int main(){
    int arr[5];
    int size=5;

    printf("enter %d elements in array: ",size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,size);
    return 0;
}