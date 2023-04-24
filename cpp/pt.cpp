#include<stdio.h>
int func(int j){ printf("%d",j);
}
int main(void)
{
	static int i=5;
	if(--i){
		printf("%d\n",i);
		func(10);
	}
}
