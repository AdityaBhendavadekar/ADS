#include<stdio.h>

void revArr(int* arr, int n, int i){

    if(i >= (n-i-1)){
        return;
    }

    int temp = arr[i];
    arr[i] = arr[n-i-1];
    arr[n-i-1] = temp;

    revArr(arr,n, i+1);
}

int main(){

    int arr[]={1,2,3,4,5};
    int n=5;
    int i=0;

    revArr(arr,n,i);

    for(int i=0;i<5;i++){
        printf(" %d ", arr[i]);
    }

    return 0;
}