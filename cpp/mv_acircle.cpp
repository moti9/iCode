#include<stdio.h>   
#include<conio.h>
#include<math.h>
#define PI 3.141  
int main()   
{  
    float radius,a,area;  
    printf("Enter radius of circle::");  
    scanf("%f",& radius);
	a=pow(radius,2);  
    area = PI * a;  
    printf("Area of circle : %0.4f\n", area);  
    
    return 0;  
} 
