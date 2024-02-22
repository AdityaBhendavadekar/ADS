#include <stdio.h>

struct Student
{
    int roll;
    char name[20];
    int marks;
} s1[5];

void sortingStruct(struct Student s1[])
{
    int size = 5;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (s1[j].roll > s1[j + 1].roll)
            {
                struct Student temp = s1[j];
                s1[j] = s1[j + 1];
                s1[j + 1] = temp;
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        printf("Enter data for %d student: ", i + 1);
        scanf("%d", &s1[i].roll);
        scanf("%s", s1[i].name);
        scanf("%d", &s1[i].marks);
    }

    sortingStruct(s1);

    for (int i = 0; i < 5; i++)
    {
        printf("\n %d student: ", i + 1);
        printf("%d ", s1[i].roll);
        printf("%s ", s1[i].name);
        printf("%d \n", s1[i].marks);
    }

    return 0;
}
