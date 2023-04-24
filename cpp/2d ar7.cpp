#include<stdio.h>
int main(void)
{
	int n,m;
	printf("Enter row and column of a Matrix: \n");
	scanf("%d %d",&n,&m);

	printf("Input Matrix:\n");
	int mt[n][m];
	for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
				{
					scanf("%d",&mt[i][j]);
				}
		}
	printf("\nFinal Matrix is:\n");
	for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
				{
					printf("%4d",mt[i][j]);
				}
			printf("\n");
		}

	printf("\nTranspose of the Given Matrix:\n");
	int trans[m][n];
	for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
				{
					trans[j][i]=mt[i][j];
				}
		}

	for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
				{
					printf("%4d",trans[i][j]);

				}
			printf("\n");
		}
}

