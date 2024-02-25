#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue *next;
};

void display(struct queue *h) {
    if (h == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct queue *temp = h;

    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void dequeue(struct queue **f, struct queue **h, struct queue **r){
    struct queue *temp;
    temp = *f;

    if(temp==NULL){
        printf("Queue underflow.\n");
        return;
    }

    printf("Dequeued element: %d\n",temp->data);
    
    if (*f == *r) { // If there's only one element in the queue
        *f = *r = NULL;
    } else {
        *f = (*f)->next; // Move front to the next element
    }

    free(temp);
}

void enqueue(struct queue **f, struct queue **h, struct queue **r ){
    struct queue *node = (struct queue*) malloc(sizeof(struct queue));
    node->next=NULL;

    printf("Enter data to insert: ");
    scanf("%d", &node->data);

    if(*h==NULL && *f==NULL){
        *h = *f = *r = node;
    }
    else{
        (*r)->next = node; // Connect the current rear to the new node
        *r = node; // Update the rear pointer to the new node
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
            dequeue(&front, &head, &rear);
            break;
        case 3:
            display(front);
            break;
        case 4:
            printf("Exiting from system...");
            break;
        default:
            printf("Enter correct option please.");

    }
    // printf("Front pointing to: %d", front->data);
    // printf("Rear pointing to: %d", head->data);

}while(option != 4); 

    return 0;
}