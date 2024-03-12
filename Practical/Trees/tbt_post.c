#include<stdio.h>
#include<stdlib.h>

struct TBTNode{
	int data, lbit, rbit;
	struct TBTNode *left, *right;
};

struct TBTNode* insert(struct TBTNode *head, int data){
	struct TBTNode *temp = (struct TBTNode*) malloc(sizeof(struct TBTNode)), *p;
	temp->data = data;
	temp->lbit = 0;
	temp->rbit = 0;
	if(head->lbit == 0){
		temp->left = head;
		temp->right = head;
		head->left = temp;
		head->lbit = 1;
		return head;
	}
	p = head->left;
	while(1){
		if(p->data > data && p->lbit == 1)
			p = p->left;
		else if(p->data < data && p->rbit == 1)
			p = p->right;
		else
			break;
	}
	if(p->data > data && p->lbit == 0){
		temp->left = p->left;
		temp->right = p;
		p->lbit = 1;
		p->left = temp;
	}
	if(p->data < data && p->rbit == 0){
		temp->left = p;
		temp->right = p->right;
		p->rbit = 1;
		p->right = temp;
	}
	return head;
}

struct TBTNode* findParent(struct TBTNode* p) {
    struct TBTNode* child = p;
    
    while (p->rbit == 1) p = p->right;
    	p = p->right;

    if (p->left == child)
        return p;

    p = p->left;
    while (p->right != child) {
        p = p->right;
    }
    return p;
}


struct TBTNode* postSucc(struct TBTNode* p) {
    struct TBTNode* cur = p;
    struct TBTNode* parent = findParent(cur);
    if (parent->right == cur) 
		return parent;
    else {
        while (p->rbit == 1) p = p->right;
        p = p->right;
        if (p->rbit == 1) {
            p = p->right;
            while (!(p->rbit == 0 && p->lbit == 0)) {
                if (p->lbit == 1) p = p->left;
                else if (p->rbit == 1) p = p->right;
            }
        }
    }
    return p;
}
void postOrderTBT(struct TBTNode* head) {
    struct TBTNode* p = head->left;
    struct TBTNode* temp = p;
    while (!(p->rbit == 0 && p->lbit == 0)) {
        if (p->lbit == 1) {
            p = p->left;
        }
        else if (p->rbit == 1) p = p->right;
    }
    printf("%d ", p->data);

    while (p != head->left) {
        p = postSucc(p);
        printf("%d ", p->data);
    }
}


int main(){
	struct TBTNode *head = (struct TBTNode*) malloc(sizeof(struct TBTNode));
	head->lbit = 0;
	head->rbit = 1;
	head->left = head;
	head->right = head;
	
    head = insert(head, 50);
    head = insert(head, 40);
    head = insert(head, 54);
    head = insert(head, 30);
    head = insert(head, 70);
    head = insert(head, 55);
	
	printf("\nPostorder Traversal is: ");
	postOrderTBT(head);
}