#include<stdio.h>
#include<math.h>

int main()
{  int n,i=0,j=0,min=0,max=0,num=-1;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  for (i = 0; i < n; i++) {
    if (num <= a[i]) {
      
      num=a[i];
    }}
  printf("%d\n",num);
  
  for(i=0;i<n;i++) 
//  for(j=i;j<n;j++) 
  {
  	if((a[i]+3)>=num) printf("TRUE\n");
  	else printf("FALSE\n");
  }
  


return 0;}

