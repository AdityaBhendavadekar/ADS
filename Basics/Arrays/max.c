#include<stdio.h>

int main(){

    int arr[5];
    printf("Enter 5 elements in array: ");
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }

    int max=arr[0];
    for(int i=1;i<5;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }

    printf("Maximum array is: %d",max);

    return 0;
}