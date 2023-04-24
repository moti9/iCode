#include<stdio.h>
int main()
{ int i,n,max=0;

 printf("Type Total No taken:");
scanf("%d",&n);

do { printf("Type No:");
scanf("%d",&i);
n--;

if(i>max){ max=i; }

else{  continue;}} 
     while(n>0);
	 printf("Largest No:%d",max);	
	return 0;
}

//   Moti Kumar Yadav 20UICS096
