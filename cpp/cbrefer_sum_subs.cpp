#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
int sum_ref(int *x,int *y){
	int sum;
	sum=*x+*y;
}
int subs_ref(int *v,int *m){
	int subs;
	subs=*v-*m;
}
int Af_run(int *i,int *j){
	int sum;
	sum=*i+*j;
	*i=sum;
	*j=sum-*j-*j;
}

 int main(){
  int a=81,b=63,sum=0,subs=0;
  printf("Before runing program\n");
  printf("\n%d\t%d\n",a,b);
  printf("\n+++++++++++++++++++++++++++++++++\n");
  sum=sum_ref(&a,&b);
  printf("\n%d\n",sum);
  printf("\n---------------------------------------\n");
  subs=subs_ref(&a,&b);
  printf("\n%d\n",subs);
  printf("\n<<<<<<<<<<<<<<<<<<<.......After running program.......>>>>>>\n");
  Af_run(&a,&b);
  printf("%d\t%d",a,b);
  printf("\n\n...**Thankyou Harry Bhaiya..Thanks a lot**...\n");
  

 return 0;}

