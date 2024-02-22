#include<stdio.h>

int palindrome(char* str, int size, int i){

    if(str[i]!=str[size-i-1]){
        return -1;
    }
    if(i>=size/2){
        return 0;
    }

    palindrome(str, size, i+=1);

}

int main(){

    char str[10]= {"madama"};

    int size=0,i=0;

    while(str[i]!='\0'){
        size++;
        i++;
    }

    // printf("%d", size);

    int check = palindrome(str,size,0);

    if(check==-1){
        printf("Not palindrome.");
    }else{
        printf("Palindrome.");
    }

    return 0;
}