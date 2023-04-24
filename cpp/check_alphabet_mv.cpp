#include<stdio.h>

int main()
{
  char alphabet,ch[]={'a','e','i','o','u','A','E','I','O','U'};
  
  printf("Enter Alphabet: ");
  scanf("%c",&alphabet);
  int count=0;
  int n=sizeof(ch)/sizeof(ch[0]);
  
  for(int i=0;i<n;i++)
  {
    if(alphabet==ch[i)
	{ 
	count++;
    break;
    }
  }
  if(count) printf("\n The Given Alphabet is VOWEL\n");
  else printf("\nThe Given Alphabet is CONSONANT\n");

  return 0;
}
