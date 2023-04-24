#include<stdio.h>
int main(void)
{ int i,j;

for(i=1;i<=4;i++){
	for(j=1;j<=6;j++){ if(i==1 & j==1){
		printf("*");}
	else if(j<=2*i -2){	
		printf("*");}		
	}printf("\n");
} 
	
}
