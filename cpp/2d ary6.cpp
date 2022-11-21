#include<stdio.h>
int main(void)
{
	int n,m,ele,count;
	printf("Enter row and column for required Matrix:\n");
	scanf("%d%d",&n,&m);

	printf("Enter First Matrix.\n");

	int mt[n][m];
	for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
				{
					scanf("%d",&mt[i][j]);
				}
		}
	for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
				{
					printf("%4d",mt[i][j]);
				}
			printf("\n");
		}
	printf("\nEnter dublicate element=");
	scanf("%d",&ele);

	for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
				{
					if(mt[i][j]==ele)
						{
							count++;
						}
				}
		}

	printf("The dublicate element %d found in Matrix = %d times.",ele,count);
}
