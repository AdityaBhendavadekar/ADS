#include<stdio.h>

int main(){

    int arr[5];

    printf("Enter 5 elements in array: ");
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }

    int key;
    int flag=0;
    printf("Enter value to search: ");
    scanf("%d",&key);

    for(int i=0;i<5;i++){
        if(key==arr[i]){
            flag=1;
            break;
        }else{
            flag=0;
        }
    }

    if(flag==1){
        printf("Element found in array");
    }else{
        printf("Element not found in array");
    }

    

    return 0;
}