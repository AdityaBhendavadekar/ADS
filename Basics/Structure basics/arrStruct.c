#include<stdio.h>

struct Stud{
    int roll;
    char name[20];
};

int main(){

    int count;
    printf("For how many students you want to enter data: ");
    scanf("%d", &count);

    struct Stud s1[count];

    for(int i=0;i<count;i++){
        scanf("%d",&s1[i].roll);
        scanf("%s",s1[i].name);
    }

       for(int i=0;i<count;i++){
        printf("\n%d ",s1[i].roll);
        printf(" %s",s1[i].name);
    }

    return 0;
}