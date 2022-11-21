#include<stdio.h>
#include<math.h>

int main()
{   int n;
    scanf("%d",&n);
    if(n%2!=0) return 0;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    int i=0;
    int j=n/2;
    int k=0;
    while(i<n/2  && j<n){
    	b[k]=a[i];
    	k++;
    	i++;
    	b[k]=a[j];
    	k++;
    	j++;
	}
	for(int i=0;i<n;i++) printf("%d \t",b[i]);
    


return 0;}

