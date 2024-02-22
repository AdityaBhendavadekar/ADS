#include<stdio.h>

int count=1;

void table(int number){
    if(count>10){
        return;
    }
    printf("%d * %d = %d\n", number, count, number*count ); 
    count++;
    return table(number);
}

int main(){
    int count=1;
    // printf("%d\n", table(5));
    table(5);
    return 0;
}