#include<stdio.h>

void reverseStr(char* str, int size, int i){
    if(i>=size/2){
        return;
    }
    char temp = str[i];
    str[i]= str[size-i-1];
    str[size-i-1] = temp;
    
    reverseStr(str, size, i+=1);
}

int main(){

    char str[10]={"madam"};

    int size = 0;
    int i=0;

    while (str[i]!='\0')
    {
        size++;
        i++;       
    }

    // printf("%d", size);

    reverseStr(str,size,0);

    printf("%s", str);

    return 0;
}