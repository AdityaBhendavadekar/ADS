#include<stdio.h>

int count=1;

int number(int number){
    if(count>10){
        return;
    }
    
    return number(number)*count++;
}

int main(){
    int count=1;
    printf("%d\n", number(5));
    return 0;
}