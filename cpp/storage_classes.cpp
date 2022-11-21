#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//int sum;
int myfunc(int a,int b){
extern int sum;//	auto int sum=a+b;//not valid int sum=a+b;
	return sum;
}
int sum=6381;//extern int sum=6381;
 int main(){
  int sum=myfunc(63,81); //not valid sum=myfunc()
  printf("The sum is %d ",sum);//144 bz sum id initialized and decleared as extern
                                //6381   
 return 0;}

