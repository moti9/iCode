#include<stdio.h>
#include<math.h>

int main()
{  int n,i=0,j=0,m,count=0,v;
 scanf("%d",&n);
 int a[n];
 for (i = 0; i < n; i++) {
    scanf("%d",&a[i]);
    }
  
 for (i = 0; i < n; i++) {
    if (a[0] < a[i]) {
      a[0] = a[i];
      m=a[i];
    }
  }
 for(i=0;i<n;i++)
 { for(j=0;j<=n-i;j++){
  	if(a[i]+ a[j]==m) {printf("(%d,%d)\t",a[i],a[j]);
	 count++; }
 }
 }
  printf("%d",count);
  if(count==0){ printf("Enter specific number= ");
  	scanf("%d",&v);
  	for(i=0;i<n;i++)
 { for(j=0;j<=n-i;j++){
  	if(a[i]+ a[j]==v) {printf("(%d,%d)\t",a[i],a[j]);
	 count++; }
 }
 }
 
  }
return 0;}

