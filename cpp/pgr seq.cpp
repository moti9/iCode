#include<stdio.h>
long int fact(int x){ int i,f=1;
if(x==0){ return f;
}
for(i=1;i<=x;i++){
	f=f*i;
	}
	return f;
	}


int main(){
	int n,i,j,k;
	long int c;
	
	//printf("Enter required number:: ");
	//scanf("%d",&n);
	
for(i=0;i<=10;i++){for(j=i;j>=0;j--){k=i;
	c=fact(k)/(fact(k)*fact(j));
	k--;
 printf("%d\t%ld",i,c);}
printf("\n");}
	
return 0;
}


//This is not completed yet

