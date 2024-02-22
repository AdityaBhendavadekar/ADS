#include<stdio.h>

void printNum(int i, int n){
// i-> n
// 1->3    3 2 1

    if(n<i){
        return;
    }  

    printNum(i+1,n);
    printf("%d ", i);  
}

int main(){

    printNum(1,3);

    return 0;
}