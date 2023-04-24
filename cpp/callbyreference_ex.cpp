#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
int swap(int *x, int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
 int main(){
  int a=5,b=10;
   
  printf("%d\t%d\n",a,b);
  printf("\n+++++++++++++++++++++++++++++++++++++\n");
swap(&a,&b);
printf("\n%d\t%d\n",a,b);
 return 0;}

