#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void displayData(struct Node *head)
{

    if (head == NULL )
    {
        printf("No data found");
        return;
    }

    struct Node* tmp = head;
    while (tmp!=NULL)
    {
        printf(" %d -> ", tmp->data);
        tmp = tmp->next;
    }
}
void createNewNode(struct Node **head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *tmp = *head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

int main()
{
    struct Node *head;

    head = NULL;
    int option;

    do
    {
        printf("\n1. Add New Node. \n 2.Display Node \n3. Exit\n");
        printf("Choose option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            createNewNode(&head);
            printf("\nNew node created\n");
            break;
        case 2:
            displayData(head);
            break;
        case 3:
            printf("Exiting from system....");
            break;
        default:
            printf("Please enter correct option.");
        }
    } while (option != 3);

    return 0;
}