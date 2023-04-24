#include<stdio.h>
#include<string.h>
struct Student {
int id;
float marks;
char name;
};
 int main(){ struct Student s1,s2,s3;
 	s1.id=6381;
 	s1.marks=99.9;
 	s1.name='V';
 	s2.id=8163;
 	s2.marks=99.5;
 	s2.name='M';
 	s3.id=63;
 	s3.marks=81;
 	s3.name='v';
printf("V's id is :: %d \n V's marks is :: %f \nV's name is :: %c\n",s1.id,s1.marks,s1.name); 
printf("\n*******************\n");
printf("M's id is :: %d \n M's marks is :: %f \nM's name is :: %c\n",s1.id,s1.marks,s1.name);
printf("\n*******************\n");
printf("v's id is :: %d  \n v's marks is :: %f \nv's name is :: %c\n",s1.id,s1.marks,s1.name);
printf("\n*******************\n");
  

 return 0;}
 
