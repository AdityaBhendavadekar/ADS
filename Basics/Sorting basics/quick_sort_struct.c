#include <stdio.h>

struct Student{
	int marks,rollno;
	char name[20];
};

void quickSort(struct Student *students,int f, int l){
	int j;
	if(f<l){
		j = partition(students, f, l);
		quickSort(students,f, j-1);
		quickSort(students, j+1, l);
	}
}

int partition(struct Student *students,int f, int l){ // f=0, l = 8;
	int i,j,p;
	struct Student temp;
	struct Student temp2 = *(students+f);
	p = (students+f)->marks;
	i = f+1;
	j = l-1;
	while(i<j){
		while(p>(students+i)->marks && i<l)
			i++;
		while(p<(students+j)->marks)
			j--;
		if(i<j){
			temp = *(students+i);
			*(students+i)= *(students+j);
			*(students+j) = temp;
		}
	}
	*(students+f)= *(students+j);
	*(students+j)= temp2;
	return j;
}

int main(){
	struct Student students[8];
	int i;
	printf("Enter Student Details (8):\n");
	for(i = 0; i<8; i++){
		printf("%d:- \n",(i+1));
		printf(" Name: ");
		scanf("%s",&students[i].name);
		printf(" Roll: ");
		scanf("%d",&students[i].rollno);
		printf(" Marks: ");
		scanf("%d",&students[i].marks);
	}
	quickSort(&students,0,8);
	printf("Marks:- \n\n\n");
	for(i = 0;i<8;i++){
		printf("Name:-%s,RollNo:-%d,Marks:-%d\n\n",students[i].name,students[i].rollno,students[i].marks);
	}
}