#include<stdio.h>

int main(){

    int arr[]={1,2,3,4,5,6};
    int j=1;

    printf("Original arr: ");
    for(int i=0;i<6; i++){
        printf("%d ", arr[i]);
    }

    for(int i=0;i<6; i+=2){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            j+=2;
    }

    printf("\nAfter alternating: ");
    for(int i=0;i<6; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}