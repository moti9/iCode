// Submitted By : MOTI KUMAR YADAV Enroll no- 20UICS096 ,DATE-21.12.2020

/* WAP to find reminder and quotient */

#include<stdio.h>
int main()
{ int dvd, dvs, rmd, quot;

printf("Type Dividend:");
scanf("%d",& dvd);

printf("Type Divisor:");
scanf("%d",& dvs);

//Calculating 
 quot= dvd/dvs;
 rmd=dvd%dvs;
 
printf("Quotient is: %d\n ",quot);
printf("Remainder is: %d ",rmd);
return 0;
	
}
