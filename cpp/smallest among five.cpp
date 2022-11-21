#include<stdio.h>
int main()
{    int i, n, lar,sm, elem;
    printf ("Enter total number of elements = ");
    scanf ("%d", & elem);
    printf ("Enter first number = ");
    scanf ("%d", &n);
    sm=n;
    for (i=1; i<= elem -1 ; i++)
    {
        printf ("Enter another number = ");
        scanf ("%d",&n);
    
        if (n<sm)
        sm=n;
    }
    printf ("\n The Smallest number is - %d", sm);
    printf ("\n****************************\n");
    return main();
}
