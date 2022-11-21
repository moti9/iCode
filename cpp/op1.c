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

//
//#include<stdio.h>
//int main()
//{
//	FILE *even, *odds;
//	int n = 100;
//	size_t k = 0;
//	even = fopen("even.txt", "w");
//	odds = fopen("odds.txt", "w");
//	for(k = 1; k < n + 1; k++)
//		{
//			k%2==0 ? fprintf(even, "\t%5d\n", k)
//			: fprintf(odds, "\t%5d\n", k);
//		}
//	fclose(even);
//	fclose(odds);
//	return 0;
//}

#include<stdio.h>
#include<stdalign.h>

int myFunction(int x, int y)
{
	return x * 0 + y;
}
int main(void)
{
//	printf("Alignment of char = %zu\n", alignof(char));
////	printf("Alignment of max_align_t = %zu\n", alignof(max_align_t));
//	printf("alignof(float[10]) = %zu\n", alignof(float[10]));
//	printf("alignof(struct{char c; int n;}) = %zu\n",
//	       alignof(struct {char c; int n;}));

//	char ch = 'a';
//	printf("%zu\n", sizeof(ch)); /* Valid, will output the size of a char object, which is always 1 for
//all platforms. */
//	printf("%zu\n", sizeof ch); /* Valid, will output the size of a char object, which is always 1 for
//all platforms. */

//	int x = 3;
//	int y = 4;
//	printf("%f\n", (float)x / y);
	int (*fn)(int, int) = &myFunction;
	int x = 42;
	int y = 123;
	printf("(*fn)(%i, %i) = %i\n", x, y, (*fn)(x, y)); /* Outputs "fn(42, 123) = 207". */
	printf("fn(%i, %i) = %i\n", x, y, fn(x, y)); /* Another form: you don't need to dereference
explicitly */
}