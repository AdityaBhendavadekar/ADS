#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void dispay(struct Node *head){
    struct Node* temp = head;

    while (temp!=NULL)
    {
        printf(" %d ", temp->data);        
        temp=temp->next;
    }
    printf("\n");
    
}

int calcLen(struct Node *head){
    struct Node* temp = head;
    int count=0;

    while (temp!=NULL)
    {    
        temp=temp->next;
        count++;
    }

    return count;   
}

void deleteAtPos(struct Node **head){
    int len = calcLen(*head);
    struct Node *tmp, *nextNode;
    tmp=*head;

    int pos;
    printf("Enter position to delete element: ");
    scanf("%d", &pos);

    for(int i=1;i<pos-1;i++){
        tmp = tmp->next;
    }
    nextNode = tmp->next;
    tmp->next = nextNode->next;
    free(nextNode);
}

void deleteEnd(struct Node **head){
    struct Node *tmp, *prevNode;
    if(*head==NULL){
        printf("List is empty.");
    }else{
        tmp = *head;

        if(tmp->next==NULL){
            free(tmp);
            *head=NULL;
            return;
        }
        
        while (tmp->next!=NULL)
        {
            prevNode = tmp;
            tmp = tmp->next;
        }
        prevNode->next =NULL;
        free(tmp);
    }
}

void deleteBeg(struct Node **head){
    struct Node *temp = *head;

    if(*head==NULL){
        printf("List is empty.");
    }else{
        *head = temp->next;
        printf("Node is deleted succefully: %d ",temp->data);
        free(temp);
    }
}

void insertAtMid(struct Node **head){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    int data, pos;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    newNode->data=data;
    newNode->next = NULL;

    printf("Enter position to insert: ");
    scanf("%d", &pos);

    int len = calcLen(*head);

    if (pos > 0 && pos <= len + 1) {
        if (pos == 1) { // Inserting at the beginning
            newNode->next = *head;
            *head = newNode;
        } else {
            struct Node* temp = *head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        printf("Data inserted at position %d\n", pos);
    } else {
        printf("Element at position %d can't be inserted because linked list is of size %d\n", pos, len);
    }
}

void insertAtEnd(struct Node **head){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    int data;
    printf("Enter data to insert(Integer): ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;

    if(*head==NULL){
        *head=newNode;
    }else{
    struct Node* temp=*head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;        
    }
}

void insertAtBeg(struct Node **head){
    struct Node* newNode;
    int data;
    newNode =(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data to insert(Integer): ");
    scanf("%d", &data);
    newNode->data=data;
    newNode->next = NULL;

    if(*head==NULL){
        *head=newNode;
        printf("data inserted at node");
    }else{
        newNode->next=*head;
        *head=newNode;
        printf("data inserted at node");
    }
    
}

int main()
{

    struct Node *head;
    head = NULL;
    int option;
    int len;

    do
    {
        printf("\n--------Menu-------");
        printf("\n1. Insert at begining \n2. Insert at End \n3. Insert at mid \n4. Delete from Begining \n5.Delete from end \n6.Delete at pos \n7. Display. \n8. Find Length \n9. Exit");
        printf("\nChoose one option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            insertAtBeg(&head);
            break;
        case 2:
            insertAtEnd(&head);
            break;
        case 3:
            insertAtMid(&head);
            break;
        case 4:
            deleteBeg(&head);
            break;
        case 5:
            deleteEnd(&head);
            break;
        case 6:
            deleteAtPos(&head);
            break;
        case 7:
            dispay(head);
            break;
        case 8:
            len = calcLen(head);
            printf("Length of linkedlist is:%d\n",len);
            break;
        case 9:
            printf("Exiting from system.");
            break;
        default:
            printf("Plz enter correct option.");
            break;
        }
    } while (option != 9);

    return 0;
}