#include <stdio.h>

int main(){

    int arr[50], n, i;

    printf("Enter the size of an Array:\n");
    scanf("%d", &n);

    printf("Enter the elements in Array:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Elements in Array are:\n");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}