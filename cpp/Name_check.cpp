#include<stdio.h>

int main ()

{
   char name[100],i,s=0;

   printf("enter your name:");
   scanf("%s",&name);

   for(i=0;i<100;i++)
   {
       if(name[i]=='0'||name[i]=='1'||name[i]=='2'||name[i]=='3'||name[i]=='4'||name[i]=='5'||name[i]=='6'||name[i]=='7'||name[i]=='8'||name[i]=='9')
       {
           printf("\a");
           break;
       }
       else if (name[i]=='\0')
       {
           break;
       }
    }
}
