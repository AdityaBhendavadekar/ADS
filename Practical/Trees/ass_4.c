#include<stdio.h>
#include<stdlib.h>

struct btree{
    int data;
    struct btree *left, *right;
};

void displayLevelWise(struct btree* root){
    struct btree *temp, *front, *rear;
    temp = dequeue(&front);
    if(temp->left==NULL){

    }
}

void displayIn(struct btree *root){

    if(root==NULL)  return;

    displayIn(root->left);
    printf(" %d ", root->data);
    displayIn(root->right);
}

struct btree* insert(struct btree *root, int data){

    if(root==NULL){
        root = (struct btree *) malloc(sizeof(struct btree));
        root->data = data;
        root->left = root->right = NULL;
    }else if(root->data < data){
        root->right = insert(root->right, data);
    }else{
        root->left = insert(root->left, data);
    }
    return root;
}

int main(){

    struct btree *root=NULL;
    int option, data;

do{
    printf("\n------Menu------n");
    printf("1.Insert \n2. Display Inorder \n3. Display Level Wise \n4.Find all leaf nodes \n5. Exit");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        root = insert(root, data);
        break;
    
    case 2: 
        displayIn(root);
        break;

    case 3: 
       displayLevelWise(root);
    
    default:
        break;
    }
}while(option!=5);

}