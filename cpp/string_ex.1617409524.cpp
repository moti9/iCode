#include<stdio.h>
#include<string.h>

 int main(){
  char s1[15];//="Moti";
  char s2[15];//="Kumar";
  char s3[]=" is a friend of "; //="Yadav";
//puts(strcat(strcat(s1,s2),s3));
//printf("%d\t%d\t%d\n",strlen(s1),strlen(s2),strlen(s3));
//puts(strrev(strcat(strcat(s1,s2),s3)));
//puts(strrev(s1));
//printf("\n%s\n",s1);
//puts(strcpy(s3,strcat(s1,s2)));
//printf("%d\n",strcmp(s1,s2));
//printf("%d\n",strcmp(s3,strcat(strcat(s1,s2),s3)));
 gets(s1);
 gets(s2);
 puts(strcat(strcat(s1 , s3), s2));
 return 0;}

