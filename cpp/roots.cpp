#include<stdio.h>
#include<math.h>
int main(void)
{ float a,b,c,dsc,root1,root2,rlpart,impart;
printf("Enter coefficient of the equation:");
scanf("%f%f%f",&a,&b,&c);
dsc=(b*b) - (4*a*c);
if(dsc>0){
	root1=(-b + sqrt(dsc))/(2*a);
	root2=(-b - sqrt(dsc))/(2*a);
printf("%.2f and %.2f",root1,root2);}

else if(dsc==0){
	root1=root2=(-b)/(2*a);
	printf("%.2f and %.2f",root1,root2);}
else{
	rlpart=(-b)/(2*a);
	impart=sqrt(-dsc)/(2*a);
	printf("Root1=%.2f + %.2fi and Root2= %.2f - %.2fi",rlpart,impart,rlpart,impart);
}		
	
}
