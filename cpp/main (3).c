/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main(void)
{ int blanks=0 ,digits=0 ,total_chars=0;
 int c;
 for(;(c = getchar()) != EOF; total_chars++)
 {
     if (c== ' ')
     ++blanks;
     else if (c>= '0' && c <= '9')
     ++digits;
 };
 printf(" blanks = %d , digits = %d , total_chars = %d\n\n", blanks, digits, total_chars);
 return 0;

}
