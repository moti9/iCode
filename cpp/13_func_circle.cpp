#include<stdio.h>
#include<math.h>
#include<conio.h>
#define PI 3.141
int diam(int r){
	return 2*r;}
float circumfr(int r){
	return 2* PI * r;}
float area_circle(int r){
	return PI* pow(r,2);}
	
int main()
{ int radius;
printf("Enter radius of the circle = ");
scanf("%d",&radius);
printf("The Diameter of the Circle = %d\n",diam(radius));
printf("The Circumference of the Circle = %0.4f\n",circumfr(radius));
printf("The Area of the Circle = %0.4f\n",area_circle(radius));

return 0;	
}
