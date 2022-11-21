#include<stdio.h>
int greater_num(int x,int y){
	int g=0;
	if(x>y){ g=x;
	}
	else {g=y;
	}
}

int main(){
	int a,b;
	printf("Enter Num1:: ");
	scanf("%d",&a);
	printf("Enter Num2:: ");
	scanf("%d",&b);
	printf("The greatest number among %d and %d = %d",a,b,greater_num(a,b));
return 0;	
}
