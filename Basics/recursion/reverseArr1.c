#include<stdio.h>

void revArr(int* arr, int l, int r){

    if(l>=r){
        return;
    }

    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;

    revArr(arr, l+1, r-1);
}


int main(){
    int arr[5]={1,2,3,4,5};
    revArr(arr, 0,4);

    for(int i=0;i<5;i++){
        printf(" %d ", arr[i]);
    }
    return 0;
}