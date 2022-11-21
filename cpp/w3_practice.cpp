#include<stdio.h>
#include<math.h>

int main()
{  int n=5,i,arr[n],sum=0,count=0;
    printf("Input the first number: ");
    scanf("%d",&arr[0]);
    printf("Input the second number: ");
    scanf("%d",&arr[1]);
    printf("Input the third number: ");
    scanf("%d",&arr[2]);
    printf("Input the fourth number: ");
    scanf("%d",&arr[3]);
    printf("Input the fifth number: ");
    scanf("%d",&arr[4]);
    for(i=0;i<n;i++){
    	if(arr[i]>0){
    		sum+=arr[i];
    		count++;
		}
		 
	}
	float d=(sum/count)*1.0;
	printf("%d %.2f",count,d);
 

return 0;}

