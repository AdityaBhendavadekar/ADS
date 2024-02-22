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

    // if(len>0 && len<pos){
    //     struct Node* temp = *head;
    //     while(len<pos){
    //         temp = temp->next;
    //         len--;
    //     }
    //     newNode->next=temp->next;
    //     temp->next=newNode;
    // }else{
    //     printf("Element at position %d cant be inserted because linked list if of size %d ", pos, len);
    // }
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
        printf("\n1. Insert at begining \n2. Insert at End \n3. Insert at mid \n4. Display. \n5. Find Length \n6. Exit");
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
            dispay(head);
            break;
        case 5:
            len = calcLen(head);
            printf("Length of linkedlist is:%d\n",len);
            break;
        case 6:
            printf("Exiting from system.");
            break;
        default:
            printf("Plz enter correct option.");
            break;
        }
    } while (option != 6);

    return 0;
}