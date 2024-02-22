#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue *next;
};

void display(struct queue *h){

    struct queue *temp = h;

    while (temp!=NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}

void enqueue(struct queue **f, struct queue **h, struct queue **r ){
    struct queue *node = (struct queue*) malloc(sizeof(struct queue));
    node->next=NULL;

    printf("Enter data insert: ");
    scanf("%d", &node->data);

    if(*h==NULL){
        *h = *f = *r = node;
    }
    else{
        *r = node;
        struct queue *tmp = *h;
            while (tmp->next != NULL)
            {
                *r = tmp = tmp->next;
            }
            tmp->next = node;
    }
}

int main(){

    struct queue *head, *rear, *front;
    head = rear = front = NULL;

    int option;

do{
    printf("\n------Options------\n");
    printf("1. Enqueue \n2.Dequeue \n3.Traverse \n4.Exit");
    scanf("%d",&option);

    switch(option){
        case 1:
            enqueue(&front, &head,&rear);
            break;
        case 2:
            // dequeue(&front, head, &rear);
            break;
        case 3:
            display(head);
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