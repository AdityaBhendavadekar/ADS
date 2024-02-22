#include<stdio.h>

void bubbleSort(int arr[], int n){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

     printf("Sorted array: ");
    for(int i=0;i<5;i++){
        printf(" %d ",arr[i]);
    } 

}

int main(){

    int arr[5]={23,45,67,34,32};
    int n=5;

    bubbleSort(arr,5);  

   
    return 0;
}