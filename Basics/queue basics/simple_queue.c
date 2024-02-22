#include<stdio.h>
#define MAX 10

void display(int r, int f, int arr[]){

    if(r==-1 || f==-1){
        printf("Queue is empty.");
    }

    while (f<=r)
    {
        printf(" %d ", arr[f]);
        f++;
    }
}

void dequeue(int *front, int arr[], int *rear){

    if(*front>*rear){
        printf("Queue underflow.");
    }

    printf("\n %d ", arr[*front]);
    (*front)++;

}

void enqueue(int *rear, int arr[], int *front){

    if(*rear>=MAX){
        printf("Queue overflow.");
        return;
    }

    int key;
    printf("Enter number to insert in queue: ");
    scanf("%d",&key);

    (*rear)++;
    arr[*rear] = key;

    if(*front==-1){
        *front = 0;
    }

}

int main(){

    int arr[MAX];
    int front=-1, rear = -1;
    int option;

do{
    printf("\n------Options------\n");
    printf("1. Enqueue \n2.Dequeue \n3.Traverse \n4.Exit");
    scanf("%d",&option);

    switch(option){
        case 1:
            enqueue(&rear, arr,&front);
            break;
        case 2:
            dequeue(&front, arr, &rear);
            break;
        case 3:
            display(rear, front, arr);
            break;
        case 4:
            printf("Exiting from system...");
            break;
        default:
            printf("Enter correct option please.");

    }
}while(option != 4);

    return 0;
}