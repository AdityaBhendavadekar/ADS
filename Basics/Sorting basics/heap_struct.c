#include <stdio.h>

struct Stud {
    int rollNo;
    float cgpa;
    char name[20];
};

void maxHeap(struct Stud arr[], int i, int size) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < size && arr[left].rollNo > arr[largest].rollNo) {
        largest = left;
    }
    if (right < size && arr[right].rollNo > arr[largest].rollNo) {
        largest = right;
    }
    if (i != largest) {
        struct Stud temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeap(arr, largest, size);
    }
}

void heapSort(struct Stud student[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeap(student, i, size);
    }

    for (int i = size - 1; i > 0; i--) {
        struct Stud temp = student[0];
        student[0] = student[i];
        student[i] = temp;

        maxHeap(student, 0, i);
    }
}

int main() {
    struct Stud student[5];

    for (int i = 0; i < 5; i++) {
        printf("\nEnter data for student%d \n", i + 1);

        printf("Enter student roll: ");
        scanf("%d", &student[i].rollNo);

        printf("Enter student name: ");
        scanf("%s", student[i].name);

        printf("Enter student cgpa: ");
        scanf("%f", &student[i].cgpa);
    }

    heapSort(student, 5);

    printf("\nSorted student data:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student roll: %d ", student[i].rollNo);
        printf("Student cgpa: %f ", student[i].cgpa);
        printf("Student name: %s ", student[i].name);
        printf("\n");
    }

    return 0;
}
