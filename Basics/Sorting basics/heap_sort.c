#include<stdio.h>

void heapSort(int arr[], int size){
    
    //for each pass this function is written. for each iteration there is maxHeap function.
    for(int i=size/2-1;i>=0;i--){
        maxHeap(arr, i, size);
    }

    for(int i=size-1;i>0;i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        maxHeap(arr, 0, i);
    }
}

void maxHeap(int arr[], int i, int size){

    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;

    if(left<size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }

    if(i != largest){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeap(arr, largest, size);
    }

}

int main(){

    int arr[9] = {32,54,76,23,75,12,99,41,63};

    heapSort(arr, 9);

    for(int i=0;i<9;i++){
        printf(" %d ", arr[i]);
    }

    return 0;
}