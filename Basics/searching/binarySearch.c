#include<stdio.h>

int binarySearch(int arr[], int size, int key){

    int low=0, high=size-1;
    int mid=(low+high)/2;

    while(low<=high){
        
        if(key==arr[mid]){
            return mid;
        }else{
            if(key<arr[mid]){   
                high=mid-1;
            }else{
                low=mid+1;
            }
            mid=(low+high)/2;
        }
    }
    return -1;
}

int main(){

    int arr[5];
    int size=5;

    printf("Enter 5 elements in ascending order in array: ");
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }

    int key;
    int flag=0;
    printf("Enter value to search: ");
    scanf("%d",&key);

   int result = binarySearch(arr,size,key);
   if(result!=-1){
    printf("%d Element found at index %d",key, result);
   }else{
    printf("%d Element not found.",key);
   }

    return 0;
}