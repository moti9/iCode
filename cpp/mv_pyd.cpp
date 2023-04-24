#include<stdio.h>
int main(void)
{
	int j=1,i,k;
	for(i=5;i>=1;i--)
	{
			for(k=5;k>=i;k--)
		{
			printf(" %d ",j);
			j++;
		}
		printf("\n");
	}
}
