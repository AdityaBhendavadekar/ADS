#include<stdio.h>

int main(){

    int arr[5];
    printf("Enter 5 elements in array: ");
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }

    int sum=0;

    for(int i=0;i<5;i++){
        sum+=arr[i];
    }

    printf("Maximum array is: %d",sum);

    return 0;
}