#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>

 int main(){ int a=15;
 int *ptr=&a;
 int **ptr2=&ptr;
 printf("%d\n",a);
 printf("%d\n",&a);
printf("%d\n",ptr);
printf("%d\n",*ptr-1);
printf("%d\n",ptr2);
printf("%d\n",&ptr);
printf("%d\n",&ptr2-2);
printf("\n.....****************************************************************.......\n");
printf("%x\n",a);
//printf("%x\n",a);
printf("%x\n",&a);
printf("%x\n",ptr);
printf("%x\n",&ptr);
printf("%x\n",&ptr);
printf("\n\n..........\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\............\n\n");
printf("%p\n",a);
printf("%p\n",&a);
//printf("%p\n",a);
printf("%p\n",ptr);
printf("%p\n",*ptr);
printf("%p\n",&ptr);

 return 0;}

