#include<stdio.h>
#include<conio.h>

int main(){

    char name[20];
    char sentence[20];

    printf("Enter name: ");
    scanf("%s",name);

    printf("name is: %s\n",name);

    gets(sentence);
    scanf("%[^\n]%*c",sentence);

    printf("Sentence is: ",sentence);

    return 0;
}