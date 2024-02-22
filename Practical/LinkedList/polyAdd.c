#include <stdio.h>
#include <stdlib.h>

struct Poly
{
    int coef;
    int expo;
    struct Poly *next;
};

void addPoly(struct Poly *poly1, struct Poly *poly2, struct Poly **poly3)
{

    while (poly1 != NULL && poly2 != NULL)
    {
        struct Poly *newNode = (struct Poly *)malloc(sizeof(struct Poly));
        newNode->next = NULL;

        if (poly1->expo == poly2->expo)
        {
            newNode->coef = poly1->coef + poly2->coef;
            newNode->expo = poly1->expo;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->expo > poly2->expo)
        {
            newNode->coef = poly1->coef;
            newNode->expo = poly1->expo;
            poly1 = poly1->next;
        }
        else
        {
            newNode->coef = poly2->coef;
            newNode->expo = poly2->expo;
            poly2 = poly2->next;
        }

        struct Poly *temp;

        if (*poly3 == NULL)
        {
            *poly3 = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

void displayPoly(struct Poly *head)
{
    struct Poly *temp = head;

    while (temp != NULL)
    {
        printf("%dX^%d  ", temp->coef, temp->expo);
        temp = temp->next;
    }
}

void createPoly(struct Poly **head, int term)
{
    int coef, expo;

    for (int i = 0; i < term; i++)
    {
        struct Poly *node = (struct Poly *)malloc(sizeof(struct Poly));

        printf("Enter coeficient: ");
        scanf("%d", &coef);
        printf("Enter exponential: ");
        scanf("%d", &expo);
        node->coef = coef;
        node->expo = expo;
        node->next = NULL;

        struct Poly *temp;

        if (*head == NULL)
        {
            *head = temp = node;
        }
        else
        {
            temp->next = node;
            temp = node;
        }
    }
}

int main()
{
    int term1, term2;
    struct Poly *poly1, *poly2, *result;

    poly1 = NULL;
    poly2 = NULL;
    result = NULL;

    printf("\nEnter for Polynomial 1: ");
    printf("\nEnter no. of terms in polynomial 1: ");
    scanf("%d", &term1);
    createPoly(&poly1, term1);

    printf("\nEnter for Polynomial 2: ");
    printf("\nEnter no. of terms in polynomial 2: ");
    scanf("%d", &term2);
    createPoly(&poly2, term2);

    printf("Polynomial 1: ");
    displayPoly(poly1);

    printf("\nPolynomial 2: ");
    displayPoly(poly2);

    addPoly(poly1, poly2, &result);

    printf("\nAddition is: ");
    displayPoly(result);
}