#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int myfunc(int a,int b){
	static int myvar;
	myvar++;
	printf("The sum is %d \n",myvar);
	return myvar;
}//int myvar=6381; //either give error
 int main(){
 register int myvar=myfunc(3,5);//int myvar=myfunc(3,5);//0-1
myvar=myfunc(3,5);//1-2
 myvar=myfunc(3,5);//2-3
 myvar=myfunc(3,5);//3-4 
//printf("The sum is %d \n",myvar);//0
 return 0;}

