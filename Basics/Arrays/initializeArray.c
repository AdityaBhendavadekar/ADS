#include<stdio.h>

int main(){

    // int arr[10]={1};

    int arr2[5]={1};

    // printf("%d",arr2[5]); //will return garbage value

    int widths[] = {[0 ... 9] = 1};
    int size;

    for(int i=0;i<10;i++){
        // printf(" %d ",arr2[i]);
        printf(" %d ",widths[i]);
    }

    size = sizeof(arr2)/sizeof(int);
    printf("\n Size of widths array is: %d ",size);

    return 0;
}