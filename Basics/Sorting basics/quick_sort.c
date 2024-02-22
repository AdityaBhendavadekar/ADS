#include<stdio.h>

int findPartition(int arr[], int low, int high){

    int i=low;
    int j=high;
    int pivot = low;

    while(i<j){
    // find first element greater than pivot.
    while (arr[i]<=arr[pivot] && i<=high){
        i++;
    }

    // find first element lesser than pivot.
    while (arr[j]>arr[pivot] && j>=low){
        j--;
    }
    
    // swap if i is less than j means i havent crossed j.
    if(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j]= temp;
    }
    } 
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
    
    return j;
}

void quickSort(int arr[], int low, int high){

    //sort array only when array has more than 1 elements.
    if(low<high){
        int partitionIndex = findPartition(arr,low,high);

        quickSort(arr,partitionIndex+1,high);
        quickSort(arr,low,partitionIndex-1);
        
    }
}

int main(){

    int arr[8]={4,6,2,5,7,9,1,3};
    int size=8;
    // for(int i=0;i<size;i++){
    //     scanf("%d", &arr[i]);
    // }

    int low= 0;
    int high=size-1;

    quickSort(arr, low, high);
    
    for(int i=0;i<8;i++){
        printf(" %d ", arr[i]);
    }
    return 0;

}