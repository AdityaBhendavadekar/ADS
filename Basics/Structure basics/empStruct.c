#include<stdio.h>
#include<conio.h>

    struct Employee{
        /* data */
        int empId;
        char name[20];
        float salary;
    }emp1;

void setEmployee(struct Employee *emp1){
    
    printf("Enter employee details\n");
    printf("Enter emp id: ");
    scanf("%d",&emp1->empId);

    printf("Enter name of emp: ");
    scanf("%s",emp1->name);

    printf("Enter salary of emp: ");
    scanf("%f",&emp1->salary);

}

void getEmployee(struct Employee *emp1){

    printf("Employee information\n");

    printf("Employee id: %d",emp1->empId);
    printf("\nName: %s",emp1->name);
    printf("\nSalary: %f",emp1->salary);

}

void main(){

    setEmployee(&emp1);
    getEmployee(&emp1);
  
    getch();
}