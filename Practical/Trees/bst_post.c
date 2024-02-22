#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct btree{
    int data;
    struct btree *left, *right;
};

struct stack{
    struct btree *N;
    struct stack *next;
};

struct btree* stackTop(struct stack *top){
    struct btree *n;
    n = top->N;
    return n;
}

bool stackEmpty(struct stack *top){

    if(top == NULL){
        return true;
    }else{
        return false;
    }
}

struct btree* pop(struct stack **top){
    struct stack *t1 = *top;
    struct btree *n = t1->N;

    // change top to next node
    *top = t1->next;
    free(t1);   //free the top
    return n;
}



void push(struct btree *temp, struct stack **top){

    struct stack *stnode = (struct stack*) malloc(sizeof(struct stack));

    stnode->next = *top;
    stnode->N = temp;
    *top = stnode;

}

void NonRecPostorder(struct btree *root){

    struct stack *top=NULL;
    struct btree *temp = root, *prev=NULL;

//pushing the left part of tree onto stack
    while (temp!=NULL)
    {
        push(temp, &top);
        temp = temp->left;
    }

    while(!stackEmpty(top)){
        temp = stackTop(top);
        if(temp->right==NULL || temp->right == prev){
            printf(" %c ", temp->data);
            pop(&top);
            prev = temp;
        }else{
            temp = temp->right;
            while (temp!=NULL)
            {
                push(temp, &top);
                temp= temp->left;
            }
        }
    }
}

struct btree* insert(struct btree *root, int data){

    if(root == NULL){
        root = (struct btree*) malloc(sizeof(struct btree));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }else if(root->data > data){
        root->left= insert(root->left, data);
    }else{
        root->right = insert(root->right, data);
    }

    return root;
}

int main(){


    struct btree *root=NULL; 
    struct btree *temp=NULL;

    root = temp = insert(root,'m');
    insert(root,'d');
    insert(root,'f');
    insert(root,'h');
    insert(root,'o');
    insert(root,'t');

    printf("Tree traversal postorder: ");
    NonRecPostorder(root);

    return 0;
}