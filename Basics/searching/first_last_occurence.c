#include<stdio.h>

void firstOccurence(int arr[], int size, int value){

    int start=0, end=size-1;
    int mid= start+(end-start)/2;
    int first=-1;

// for finding first occurrence index 
    while (start<=end)
    {
        if(value==arr[mid]){
            first=mid;
            end = mid-1;
        }
        else if(value>arr[mid]){
            start=mid+1;
        }else if(value<arr[mid]){
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    
    printf("first occurence: %d", first);
}

void lastOccurence(int arr[], int size, int value){

    int start=0, end=size-1;
    int mid= start+(end-start)/2;
    int last=-1;

// for finding last occurrence index 
    while (start<=end)
    {
        if(value==arr[mid]){
            last=mid;
            start = mid+1;
        }
        else if(value>arr[mid]){
            start=mid+1;
        }else if(value<arr[mid]){
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    
    printf("last occurence: %d", last);



}

int main(){

    int arr[5];
    int size=5;

    printf("Enter 5 elements in ascending order in array: ");
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }

    int key;
    printf("Enter value to search: ");
    scanf("%d",&key);

    firstOccurence(arr,size, key);
    lastOccurence(arr,size, key);


    return 0;
}