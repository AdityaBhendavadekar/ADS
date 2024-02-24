#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct BST{
    int data;
    struct BST *left, *right;
};

struct queue{	
	struct BST *data;
	struct queue *next;
};

struct stack{
    struct BST *N;
    struct stack *next;
};

struct BST* pop(struct stack **top){
    struct stack *t1 = *top;
    struct BST *temp = t1->N;
    *top = t1->next;
    free(t1);
    return temp;
}

bool isStackEmpty(struct stack *top){
    return (top == NULL); // Returns true if stack is empty, false otherwise
}

void push(struct BST *data, struct stack **top){
    struct stack *stnode = (struct stack*)malloc(sizeof(struct stack));
    stnode->next = *top;
    stnode->N = data;
    *top = stnode;
}

void enQueue(struct BST *data, struct queue **front,struct queue **rear){
	if(data == NULL)
		return;
	struct queue *temp = (struct queue*) malloc (sizeof(struct queue));
	temp->data = data;
	temp->next = NULL;
	if((*front) == NULL){
		(*front) = temp;
		(*front)->next = NULL;
		(*rear) = temp;
		(*rear)->next = NULL;
		return;
	}
	(*rear)->next = temp;
	(*rear) = temp;
}
struct BST* deQueue(struct queue **front){
	struct BST *temp = (*front)->data;
	struct queue *temp2 = (*front);
	(*front) = temp2->next;
	free(temp2);
	return temp;
} 

struct BST* mirror(struct BST *root){
	struct stack *top = NULL;
	struct BST *temp, *curr = root;
	push(curr, &top);
	while(isStackEmpty(top)){
		curr = pop(&top);
		temp = curr->left;
		curr->left = curr->right;
		curr->right = temp;
		if(curr->left != NULL)
			push(curr->left,&top);
		if(curr->right != NULL)
			push(curr->right,&top);
	}
	return root;
}

void levelWise(struct BST *root){
	struct queue *front = NULL, *rear = NULL;
	struct BST *temp;
	enQueue(root, &front, &rear);
	while(front != NULL){
		temp = deQueue(&front);
		printf("%d ",temp->data);
		enQueue(temp->left, &front, &rear);
		enQueue(temp->right, &front, &rear);
	}
}

int findHeight(struct BST* root) {
    if (root == NULL)
        return -1; 

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void displayLeafs(struct BST *root){
    if (root == NULL)
        return;

    struct BST *current = root;
    struct stack *top = NULL;

    while (1) {
        while (current != NULL) {
            push(current, &top);
            current = current->left;
        }
        if (isStackEmpty(top))
            break;
        current = pop(&top);
        if (current->left == NULL && current->right == NULL) {
            printf("%d ", current->data);
        }
        current = current->right;
    }
}

struct BST* deletion(struct BST *root, int key){
	if(root == NULL){
		return root;
	}
	else if(root->data > key)
		root->left = deletion(root->left, key);
	else if(root->data < key)
		root->right = deletion(root->right, key);
	else{
		if(root->left == NULL){
			struct BST *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			struct BST *temp = root->left;
			free(root);
			return temp;
		}
        struct BST *temp = root->right;
        while (temp->left!=NULL){
            temp=temp->left;
        }
        root->data = temp->data;
        root->right = deletion(temp->right, temp->data);       
	}	
    return root;
}


void displayIn(struct BST *root){
    if(root==NULL)  return;

    displayIn(root->left);
    printf(" %d ", root->data);
    displayIn(root->right);
}

struct BST* insert(struct BST *root, int data){
    if(root==NULL){
        root = (struct BST *) malloc(sizeof(struct BST));
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
    struct BST *root=NULL;
    int option, data, delete;

do{
    printf("\n------Menu------\n");
    printf("1.Insert \n2. Display Inorder \n3. Delete \n4.Find all leaf nodes \n5. Display Height of Tree \n6.Mirror image of BST \n7.Display level wise \n8. Exit");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        root=insert(root, 50);
        root=insert(root, 57);
        root=insert(root, 30);
        root=insert(root, 20);
        root=insert(root, 35);
        root=insert(root, 75);
        break;

    case 2: 
        displayIn(root);
        break;

    case 3: 
        printf("enter data to delete: ");
        scanf("%d", &delete);
        root= deletion(root,delete);
        break;

    case 4:
        printf("Leaf nodes are: ");
        displayLeafs(root);
        break;

    case 5:
        printf("Hegith of tree is: %d",findHeight(root));
        break;

    case 6: 
       root = mirror(root);
       displayIn(root);
        break;
    case 7: 
        levelWise(root);
        break;

    default:
        break;
    }
}while(option!=8);

}