#include <stdio.h>

int main(void) {
	// your code goes here
	int i,j,n,sum=0,temp;
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)
	{
	    scanf("%d",&A[i]);
	}
	    
	for(i=0;i<n;i++)
	{
	    for(j=1;;j++)
	    {
	        temp=A[i] % 10;
	        if(j==1 && (i==0 || i==n-1))
	        {
	         sum += temp;   
	        }
	        if(temp == 0 )
	        {
	            sum += A[i];
				break;
	        }
			A[i]/=10;
        }
	}
		printf("%d\n",sum);
	return 0;
}
