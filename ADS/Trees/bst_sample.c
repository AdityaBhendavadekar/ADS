#include<stdio.h>
#include<stdlib.h>

struct Tree{
    int data;
    struct Tree *left, *right;
};

void postorder(struct Tree *root){
    if(root!=NULL){
        inorder(root->left);
        inorder(root->right);
        printf(" %d ", root->data);
    }
    return;
}

void preorder(struct Tree *root){
    if(root!=NULL){
        printf(" %d ", root->data);
        inorder(root->left);
        inorder(root->right);
    }
    return;
}

void inorder(struct Tree *root){
    if(root!=NULL){
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
    return;
}

struct Tree* insert(struct Tree *root, int data){

    if(root==NULL){
        root = (struct Tree*) malloc(sizeof(struct Tree));
        root->data=data;
        root->left=root->right=NULL;
        return root;
    }
    else if(data > root->data){
        root->right = insert(root->right, data);
    }else{
        root->left = insert(root->left, data);
    }
        return root;
}

int main(){
    struct Tree *root=NULL;
    struct Tree *temp;

    temp = root= insert(root, 50);
    root= insert(root, 40);
    root= insert(root, 60);
    root= insert(root, 30);
    root= insert(root, 45);
    root= insert(root, 55);

    printf("Inorder: \n");
    inorder(temp);

    printf("\nPreorder: \n");
    preorder(temp);

    printf("\nPostorder: \n");
    postorder(temp);

    return 0;
}