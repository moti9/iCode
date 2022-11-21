#include <stdio.h>
 #include <conio.h>
 int main()
{    int a[1000],i,n,min,max;
   
    printf("Enter size of the array = ");
    scanf("%d",&n);
 
    printf("Enter elements in array.\n ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);}
 
    min=max=a[0];
    for(i=1; i<n; i++){
         if(min>a[i])
		  min=a[i];   
		   if(max<a[i])
		    max=a[i];       
    }
     printf("Minimum element in an Array = %d",min);
          printf("\nMaximum element in an Array= %d",max);
 
    return 0;
}
