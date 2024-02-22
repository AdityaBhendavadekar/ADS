#include<stdio.h>

int sum(int n, int s){
    if(n<1){
        return s;
    }
    sum(n-1,s+n);
}

int sum2(int n, int s){

}

int main(){

    printf("Sum of %d is %d", 3 , sum(3,0));

    return 0;
}