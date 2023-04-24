#include<stdio.h>
int main()
{ int marks;
printf("Type Obtained Marks:");
scanf("%d",& marks);

 if ( marks<50 ){	printf("\n The Grade is F");}

else if(marks>=50 && marks<=59){	printf("\n The Grade Is E-Conditional Pass");}

else if(marks<=69 && marks>= 60){	printf("\n The Grade is PASS");}

else if(marks>=70 && marks<=79){  printf("\n The Grade is GOOD");}
 
 else if(marks<=89 && marks >=80){  printf("\n The Grade is VERY GOOD"); }
 
 else if(marks>=90){  printf("\n The Grade is EXCELLENT"); }
	
else{
printf("...Invalid...");}
	return 0;
}

//Created By Moti Kumar Yadav 20UICS096 date: 29/12/2020
