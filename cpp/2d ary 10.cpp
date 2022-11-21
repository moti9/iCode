#include<stdio.h>
int main(void)
{ int n,m,det=0;
printf("Enter rows and columns of Square Matrix(3 * 3):");
scanf("%d%d",&n,&m);

printf("\nInput element of Matrix:\n");
int mt[n][m];
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		scanf("%d",&mt[i][j]);}}
printf("\nFinal Matrix:\n");
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		printf("%4d",mt[i][j]);}
		printf("\n");}
		
   int x = (mt[1][1] * mt[2][2]) - (mt[2][1] * mt[1][2]);
   int y = (mt[1][0] * mt[2][2]) - (mt[2][0] * mt[1][2]);
    int z = (mt[1][0] * mt[2][1]) - (mt[2][0] * mt[1][1]);
	
	det = (mt[0][0] * x) - (mt[0][1] * y) + (mt[0][2] * z);
  	

printf("\nThe Determinant of the Given matrix is= %d\n",det);
}
