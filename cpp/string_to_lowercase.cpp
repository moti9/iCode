#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>

 int main(){ char S[1000];
 scanf("%s",&S);
 for(int i=0;S!='\0';i++){
 	if(S[i]='A'){ S[i]='a'; }
    else if(S[i]='B'){ S[i]='b'; }
    else if(S[i]='C'){ S[i]='c'; }
    else if(S[i]='D'){ S[i]='d'; }
    else if(S[i]='E'){ S[i]='e'; }
    else if(S[i]='F'){ S[i]='f'; }
    else if(S[i]='G'){ S[i]='g'; }
    else if(S[i]='H'){ S[i]='h'; }
    else if(S[i]='I'){ S[i]='i'; }
    else if(S[i]='J'){ S[i]='j'; }
    else if(S[i]='K'){ S[i]='k'; }
    else if(S[i]='L'){ S[i]='l'; }
    else if(S[i]='M'){ S[i]='m'; }
    else if(S[i]='N'){ S[i]='n'; }
    else if(S[i]='O'){ S[i]='o'; }
    else if(S[i]='P'){ S[i]='p'; }
    else if(S[i]='Q'){ S[i]='q'; }
    else if(S[i]='R'){ S[i]='r'; }
    else if(S[i]='S'){ S[i]='s'; }
    else if(S[i]='T'){ S[i]='t'; }
    else if(S[i]='U'){ S[i]='u'; }
    else if(S[i]='V'){ S[i]='v'; }
    else if(S[i]='W'){ S[i]='w'; }
    else if(S[i]='X'){ S[i]='x'; }
    else if(S[i]='Y'){ S[i]='y'; }
    else if(S[i]='Z'){ S[i]='z'; }
    else { continue; }
 }
 for(int i=0;S!='\0';i++){
 	printf("%s",S[i]);
 }


 return 0;}

