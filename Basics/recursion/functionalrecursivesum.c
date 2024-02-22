#include<stdio.h>

int getSum(int n){
    if(n == 0){
        return 1;
    }

    return n * getSum(n-1);
}

int main(){
    printf("%d", getSum(5));
    return 0;
}