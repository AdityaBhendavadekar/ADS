#include<stdio.h>
#define MAX 10
int queue[MAX];

void display(int *front, int *rear){
    int i=(*front);

    if((*front)==-1 && (*rear)==-1){
        printf("Queue underflow.");
    }else{
        printf("Queue is: ");
        while (i<=(*rear))
        {
            printf("%d ", queue[(i)]);
            i = (i+1) % MAX;
        }
    }
}

void dequeue(int data, int *front, int *rear){

    if((*front)==-1 && (*rear)==-1){
        printf("Queue empty.");
    }else if((*front)==(*rear)){  //this means only one element is left then assign -1.
        (*front) = (*rear) =-1;
    }else{
        printf(" %d ",queue[(*front)]);
        (*front) = ((*front)+1)%MAX;
    }
}

void enqueue(int data, int *front, int *rear){

    if((*front)==-1){
        (*front) = (*rear) =0;
        queue[(*rear)] = data;
    }
    else if((((*rear)+1) % MAX==(*front))){
        printf("Queue overflow.");
    }else{
        (*rear) = ((*rear)+1)%MAX;
        queue[(*rear)] = data;
    }
}

int main(){
    int front =-1, rear =-1;

    enqueue(5,&front, &rear);
    enqueue(6,&front, &rear);
    enqueue(7,&front, &rear);
    enqueue(8,&front, &rear);
    enqueue(9,&front, &rear);
    enqueue(10,&front, &rear);

    display(&front, &rear);
    return 0;
}