#include<stdio.h>
int main()
{
  char alphabet,ch[]={'a','e','i','o','u','A','E','I','O','U'};
  
  printf("Enter Alphabet: ");
  scanf("%c",&alphabet);
  int flag =1;
  for(int i=0;i<10;i++){
  	if(alphabet==ch[i]) { flag=0;
  	break;
	  }
  }
  if(flag) printf("\n The Given Alphabet is CONSONANT\n");
  else printf("\nThe Given Alphabet is VOWEL\n");

  return 0;
}
