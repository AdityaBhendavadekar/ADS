#include<stdio.h>

int main(){

    int arr[5];
    printf("Enter 5 elements in array: ");
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }

    int min=arr[0];
    for(int i=1;i<5;i++){
        if(min>arr[i]){
            min=arr[i];
        }
    }

    printf("Minimum array is: %d",min);

    return 0;
}