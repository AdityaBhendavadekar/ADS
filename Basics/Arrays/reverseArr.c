#include<stdio.h>

int main(){

    int size;
    printf("Enter size<100: ");
    scanf("%d",&size);

    int arr[100];

    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    int start=0, end=size-1, temp;

    do{
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }while (!(start>end));   

    for(int i=0;i<size;i++){
        printf(" %d ",arr[i]);
    }

    return 0;
}