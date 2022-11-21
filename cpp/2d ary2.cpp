#include<stdio.h>
int main(void)
{ int n,m;
printf("Enter row and column for required Matrix:");
scanf("%d%d",&n,&m);

printf("Enter First Matrix.\n");

int m1[n][m];
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		scanf("%d",&m1[i][j]);
	}}
printf("Enter second Matrix.\n");	

	int m2[n][m];
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		scanf("%d",&m2[i][j]);
	}}	
printf("Multiplication of Two Matrices:\n");
int mul[n][m];
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){ mul[i][j]=0;
		for(int o=0;o<m;o++){
			mul[i][j]+=m1[i][o]*m2[o][j];}}}
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		printf("%4d",mul[i][j]);
	}
	printf("\n");
}				
}
