#include<stdio.h>

void reversePrint(int n){
    if(n<1){
        return;
    }
    //    printf("%d\n", n);

   reversePrint(--n);
       printf("%d\n", n);
}

int main(){
    reversePrint(10);
    return 0;
}