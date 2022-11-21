#include<stdio.h>
#include<math.h>
int main()
{ int i,j,row,column;
    printf("Enter required no of Row=");
    scanf("%d",&row);
    printf("Enter required no of Column=");
    scanf("%d",&column);
	printf("Enter Matrix:\n");
	int Mat[row][column];
for(i=0;i<row;i++){
    for(j=0;j<column;j++){
         scanf("%d\t",&Mat[i][j]);
    }
} 
printf("Array in 2D look likes:\n Printable Matrix is given below:\n");
for(i=0;i<row;i++){
    for(j=0;j<column;j++){
         printf("%4d",Mat[i][j]);
    }printf("\n");
}
return 0;
}
