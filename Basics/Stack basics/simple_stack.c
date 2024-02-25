#include<stdio.h>
#define MAX 10

void traverse(int arr[], int top){
    int temp = top;

    if(temp==-1){
        printf("Stack underflow.");
    }

    printf("Elements in stack are: ");
    for(int i=temp;i>=0;i--){
        printf( " %d ",arr[i]);
    }
}

void topEl(int arr[], int top){
    printf("Topped element is: %d",arr[top]);
}

int pop(int arr[], int top){
    int popped;

    if(top ==-1){
        printf("Stack underflow.");
    }

    printf("Popped element: %d",arr[top]);
    top--;

    return top;
}

int push(int arr[], int key, int top){

    if((top)>MAX){
        printf("Stack overflow.");
    }
    top++;
    arr[top]=key;

    return top;
}

int main(){

    int arr[MAX];
    int top=-1;
    int option,data;

    do{
        printf("\n\n---choose option--- \n1.Push data \n2.Pop Data \n3.Top Data \n4. Traverse Stack \n5. Exit\n");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                top = push(arr, data, top);
                break;
            
            case 2: 
                top = pop(arr,top);
                break;
            
            case 3: 
                topEl(arr,top);
                break;

            case 4: 
                traverse(arr, top);
                break;

            case 5:
                printf("Exiting from the system...");
                break;
            
            default: 
                printf("Enter correct option. ");
        }
    }while(option!=5);

    return 0;
}