#include<stdio.h>


void number(int count){
    if(count>10){
        return;
    }
    printf("%d", count++);
    number(count);
}

int main(){
    int count=1;
    number(1);
    return 0;
}