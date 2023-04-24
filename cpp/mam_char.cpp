#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>

int main ()

{    char s[100];
    scanf("%c",&s);
    int i,j,count=0,max=0,x;

    for(i=0;s[i]!='\0';i++){
        for(j=i;s[j]!='\0';j++){
            if(s[i]==s[j]){
                count++;
            }
        }}
    
              if(count>=max){
            i=x;
            max=count;
        }
    
    printf("The Highest frequency character is %c\nappears number of times :%d",s[x],max);
    return 0;
}

