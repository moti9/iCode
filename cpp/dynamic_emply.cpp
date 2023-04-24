#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

 int main(){
  int chars,i=0;
  char a,b;
  char *ptr;
  while(i<3){
  	printf("Employee %d :: Enter the number of characters in employee Id\n",i+1);
  	scanf("%d",&chars);
  	getchar();
  	printf("Enter the value of a\n");
  	scanf("%c",&a);//can't enter value of a...so use getchar()
  	getchar();
	  printf("Enter the value of b\n");
  	scanf("%c",&b);
  	ptr=(char*)malloc((chars+1)*sizeof(char));
  	printf("Enter your employee Id\n");
  	scanf("%s",ptr);
  	printf("Your employee Id is %s\n",ptr);
  	free(ptr);
  	
  }

 return 0;}

