#include<stdio.h>

int count=1;

void number(){
    if(count>=10){
        return;
    }
    printf("%d", count++);
    number();
}

int main(){
    number();
    return 0;
}