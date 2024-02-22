#include<stdio.h>
#include<stdlib.h>

struct Poly{
    int coef;
    int expo;
    struct Poly* next;
};

void displayPoly(struct Poly *head){
    if(head==NULL){
        printf("\nNo data found.\n");
    }

    struct Poly *temp = head;
    while (temp->next!=NULL)
    {
        printf(" %d x^ %d ", temp->coef, temp->expo);
        temp = temp->next;
    }
}

void addPoly(struct Poly *poly1, struct Poly *poly2, struct Poly **poly3){ //poly 3 as a head of 3rd linked list.
   
    while (poly1!=NULL && poly2!=NULL){

        struct Poly *newNode = (struct Poly*) malloc(sizeof(struct Poly));
        newNode->next=NULL;

        if(poly1->expo == poly2->expo){
            newNode->coef = poly1->coef+poly2->coef;
            newNode->expo = poly1->expo;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if(poly1->expo > poly2->expo){
            newNode->coef = poly1->coef;
            newNode->expo = poly1->expo;
            poly1 = poly1->next;
        }
        else{
            newNode -> coef = poly2->coef;
            newNode->expo = poly2->expo;
            poly2 = poly2->next;
        }

        if(*poly3==NULL){
            *poly3=newNode;
        }else{
            struct Poly *tmp = *poly3;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
    }
}

void createPoly(int term1, struct Poly **head){

    for(int i=0;i<term1;i++){
        struct Poly *newNode = (struct Poly *) malloc(sizeof(struct Poly)); 

        printf("Enter coefficient: ");
        scanf("%d", &newNode->coef);
        printf("Enter exponent: ");
        scanf("%d", &newNode->expo);

        newNode->next = NULL;

        if(*head==NULL){
            *head = newNode;
        }
        else
        {
            struct Poly *tmp = *head;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
    }
}

int main(){

    struct Poly *poly1, *poly2, *poly3;
    // poly1 as head1, poly2 as head2, poly3 as head3;

    int term1, term2;

    poly1=NULL;
    poly2=NULL;
    poly3=NULL;

    printf("Enter no of terms in polynomial 1: ");
    scanf("%d", &term1);
    createPoly(term1, &poly1);

    printf("Enter no of terms in polynomial 2: ");
    scanf("%d", &term1);
    createPoly(term1, &poly2);

    printf("Polynomial 1: ");
    displayPoly(poly1);

    printf("Polynomial 2: ");
    displayPoly(poly2);

    addPoly(poly1, poly2, &poly3);

    printf("Addition: ");
    displayPoly(poly3);

    return 0;
}