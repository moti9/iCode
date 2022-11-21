#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */
int main(void)
{ 
double interval,i;

for(i = 0.0; i <30.0; i++)
{
 interval = i/10.0;
 printf("sin( %lf ) = %lf \n", interval,  abs(sin(interval)));
}


printf("\n+++++++\n");
return 0;
}
