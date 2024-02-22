#include<stdio.h>

struct Stud{
    int rollNo;
    char name[20];
    float marks;
};

int findPartition(struct Stud students[], int low, int high){

    int i=low;
    int j=high;
    int pivot=low;

    while(i<j){
        while(students[i].rollNo <= students[pivot].rollNo && low <= high){
            i++;
        }
        while(students[j].rollNo > students[pivot].rollNo && high >=low){
            j--;
        }
        if(i<j){
            struct Stud temp = students[i];
            students[i] = students[j];
            students[j] = temp;
        }
    }
    struct Stud temp = students[low];
    students[low] = students[j];
    students[j] = temp;

    return j;
}

void quickSort(struct Stud students[], int low, int high){
    
    if(low<high){
    int partitionIndex = findPartition(students, low, high);

    quickSort(students, low, partitionIndex);
    quickSort(students, partitionIndex+1, high);
    }
}

int main(){
    struct Stud students[5];
    printf("Enter data for 5 students");

    for(int i=0;i<5;i++){
        printf("\nData for student %d\n", i+1);
        printf("Enter roll no: ");
        scanf("%d", &students[i].rollNo);

        printf("Enter Name: ");
        scanf("%s", students[i].name);

        printf("Enter Marks: ");
        scanf("%f", &students[i].marks);
    }

    quickSort(students, 0, 4);

    printf("students data: \n");
    for(int i=0;i<5;i++){
        printf("Roll No: %d ",students[i].rollNo);
        printf("Name:%s ", students[i].name);
        printf("Marks:%f ",students[i].marks);
        printf("\n");
    }

    return 0;
}