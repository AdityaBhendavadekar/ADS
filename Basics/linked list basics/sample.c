#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    int *next;
};

int main(){

    struct Node *head, *newNode, *temp;

    //initially head is null.
    head = NULL;

    //dynamic memory allocation.
    newNode = (struct Node*) malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);   // entering data into node.

    if(head==0){
        head = temp = newNode;   // if head is null then assign temp and head nodes as newNode.
    }else{
        temp->next=newNode;      // if head is not null means there is at least one node present. 
        temp = newNode;         // so initialize temps->next pointer to new node. which will store address of new node into previous nodes address.
    }                           //and then initialize temp to newNode.

    //traversing 
    temp = head;        // assigning head to temp so that we can traverse from start
    printf("%d", temp->data);

    return 0;
}