#include<stdio.h>

int main(){

    int arr[10]={0};

    int size = sizeof(arr)/sizeof(int);
    printf("Size of arr is: %d",size);

    return 0;
}