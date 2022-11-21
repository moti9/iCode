//#include<stdio.h>
//
//int main()
//{
//	int x=5;
//	int y=10;
//	int z=15;
//	int z1=20;
//	x!=y?(
//	    printf("%d\n",x);
//	    printf("%d\n",y);
//	    printf("%d\n",z);
//	    printf("%d\n",z1);)
//	:(printf("False\n");
//	  printf("False\n"););
//
//	//
//	//	int x=5;
//	//	int y=5;
//	//	int *xp,*yp;
//	//	xp=&x;
//	//	yp=&y;
//	//	(xp==yp)? printf("True\n"):printf("False\n");
//
//	return 0;
//}
#include<stdio.h>
int main()
{
	FILE *even, *odds;
	int n = 100;
	size_t k = 0;
	even = fopen("even.txt", "w");
	odds = fopen("odds.txt", "w");
	for(k = 1; k < n + 1; k++)
		{
			k%2==0 ? fprintf(even, "\t%5d\n", k)
			: fprintf(odds, "\t%5d\n", k);
		}
	fclose(even);
	fclose(odds);
	return 0;
}