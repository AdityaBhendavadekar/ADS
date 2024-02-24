#include<stdio.h>
#include<stdlib.h>

struct BST{
    int data;
    struct BST *left, *right;
};

void inorder(struct BST *root){
    if(root == NULL) return;
    inorder(root->left);
    printf(" %d ", root->data);
    inorder(root->right);
}

struct BST* insert(struct BST *root, int data){
    if(root==NULL){
        root = (struct BST*) malloc(sizeof(struct BST));
        root->data = data;
        root->left=NULL;
        root->right=NULL;
    }
    else if(root->data < data ){
        root->right = insert(root->right, data);
    }else{
        root->left = insert(root->left, data);
    }
    return root;
}

int main(){
    struct BST *root=NULL;

    root = insert(root,67);
    insert(root,45);
    insert(root,40);
    insert(root,50);
    insert(root,70);
    insert(root,75);

    printf("Tree traversal inorder: ");
    inorder(root);
    
    return 0;
}