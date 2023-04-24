#include<stdio.h>

int main()
{
//	(1==10)? printf("True\n"):printf("False\n");

	int x=5;
	int y=5;
	int *xp,*yp;
	xp=&x;
	yp=&y;
	(xp==yp+4)? printf("True\n"):printf("False\n");

	return 0;
}