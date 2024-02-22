#include<stdio.h>

struct Student{
    int rollNum;
    char name[20];
    char s1[20];
    char s2[20];
    char s3[20];
    int s1Max;
    int s2Max;
    int s3Max;
    int s1Marks;
    int s2Marks;
    int s3Marks;
    float result;
};

void setData(struct Student *s){
    printf("Enter roll num: ");
    scanf("%d",&s->rollNum);
    
    printf("Enter first subject name: ");
    scanf("%s",s->s1);

    printf("Enter second subject name: ");
    scanf("%s",s->s2);

    printf("Enter second subject name: ");
    scanf("%s",s->s3);

    printf("Enter max marks for subject 1, 2 and 3");
    scanf("%d",&s->s1Max);
    scanf("%d",&s->s2Max);
    scanf("%d",&s->s3Max);

    printf("Enter obtained marks for subject 1 out of (%d)",s->s1Max);
    scanf("%d",&s->s1Marks);

    printf("Enter obtained marks for subject 2 out of (%d)",s->s2Max);
    scanf("%d",&s->s2Marks);

    printf("Enter obtained marks for subject 3 out of (%d)",s->s3Max);
    scanf("%d",&s->s3Marks);

    int totalMax= s->s1Max+s->s2Max+s->s3Max;
    int totalObt =s->s1Marks + s->s2Marks + s->s3Marks;

    s->result= 10.7;

    printf("Result of student %s", s->name," is %f", s->result);
}


int main(){

    struct Student s1;

    setData(&s1);

    // getData(&s1);

    return 0;
}