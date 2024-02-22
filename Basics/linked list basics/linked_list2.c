#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void displayData(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        printf("No data found\n");
        return;
    }

    struct Node *tmp = head;
    while (tmp != NULL)
    {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void createNewNode(struct Node **head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

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
    struct Node *head = NULL;
    int option;

    do
    {
        printf("1. Add New Node\n2. Display Node\n3. Exit\n");
        printf("Choose option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            createNewNode(&head);
            break;
        case 2:
            displayData(head);
            break;
        case 3:
            printf("Exiting from the system....\n");
            break;
        default:
            printf("Please enter a correct option.\n");
        }
    } while (option != 3);

    // Free allocated memory before exiting
    struct Node *tmp = head;
    while (tmp != NULL)
    {
        struct Node *nextNode = tmp->next;
        free(tmp);
        tmp = nextNode;
    }

    return 0;
}
