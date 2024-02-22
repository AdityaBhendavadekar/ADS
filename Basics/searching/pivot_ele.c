#include<stdio.h>

int privote1(int arr[], int size){
    int s=0,e=size-1;
    int mid=s+(e-s)/2;

    while (s<e)
    {
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}

int privote2(int arr[], int size){
    int s=0,e=size-1;
    int mid=s+(e-s)/2;

    while (s<e)
    {
        if(arr[mid]>=arr[0]){
            s=mid;
        }else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return s;
}

int main(){
    int arr[5]={8,10,17,20,25};

    printf("Pivot element is: %d",arr[privote1(arr,5)]);
    printf("Pivot element is: %d",arr[privote2(arr,5)]);
    

    return 0;
}