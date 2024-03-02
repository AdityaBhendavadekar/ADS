#include<stdio.h>
#include<stdlib.h>

struct BST{
    int data;
    struct BST *left, *right;
};

struct queue{
    struct BST *n;
    struct queue *next;
};

struct BST* dequeue(struct queue **front){
    struct BST* temp = (*front)->n;
    struct queue *t2 = (*front);
    
    (*front) = t2->next;
    free(t2);
    return temp; 
}

void enqueue(struct BST *root, struct queue **front, struct queue **rear){
    if (root==NULL)
    {
        return;
    }

    struct queue *temp = (struct queue*) malloc(sizeof(struct queue));
    temp->n = root;
    temp->next = NULL;

    if((*front)==NULL){
        (*front) = temp;
        (*rear) = temp;
        (*front)->next = NULL;
        (*rear)->next = NULL;
        return;
    }

    (*rear)->next=temp;
    (*rear) = temp;
    
}

void levelWise(struct BST *root){
    struct queue *rear=NULL, *front=NULL;
    struct BST *temp=NULL;

    enqueue(root, &front, &rear);

    while(front!=NULL){
        temp = dequeue(&front);
        printf(" %d ", temp->data);
        enqueue(root->left, &front, &rear);
        enqueue(root->right, &front, &rear);
    }
}

struct BST* deletion(struct BST *root, int key){

    // searching element in tree for deletion.
    if(root==NULL){
        return root;
    }
    else if(root->data > key){  //if key is to be deleted is greater than data go to right
        root->left = deletion(root->left, key);
    }
    else if(root->data < key){    //if key is to be deleted is greater than data go to right
        root->right = deletion(root->right, key);
    }
    else{    // if all above conditions get false then we found the element to be deleted.

        // checking if node to be deleted has 0 1 or 2 childs.
         struct BST *temp;
        if(root->left == NULL){
            temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            temp = root->left;
            free(root);
            return temp;
        }

        temp = root->right;
        while(temp->left!=NULL){
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = deletion(root->right, key);
    }
    return root;
}

void display(struct BST *root){

    if(root==NULL){
        return;
    }

    display(root->left);
    printf(" %d ", root->data);
    display(root->right);
}

struct BST* insert(struct BST *root, int data){
    
    if(root==NULL){
        root = (struct BST*) malloc(sizeof(struct BST));
        root->data = data;
        root->left = root->right = NULL;
    }
    else if(root->data > data){
        root->left = insert(root->left, data);
    }else if(root->data < data){
        root->right = insert(root->right, data);
    }

}

int main(){

    struct BST *node = NULL;

    node = insert(node, 50);
    node = insert(node, 40);
    node = insert(node, 60);
    node = insert(node, 30);
    node = insert(node, 70);
    node = insert(node, 45);


    printf("Before deletion: ");
    display(node);

    node = deletion(node, 30);

    printf("\nAfter deletion: ");
    display(node);

    printf("Level wise display: ");
   // levelWise(node);

    return 0;
}