#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>

 int main(){
  int arr[]={1,2,3,4,5};
  printf("%d\n",arr[0]);
  printf("%d\n",arr[1]);
   printf("%d\n",arr[2]);
    printf("%d\n",arr[3]);
     printf("%d\n",arr[4]);
      printf("\n++++++++++++++++++++++++++++++++++++\n");
       printf("%d\n",&arr[0]);
        printf("%d\n",&arr[1]);
         printf("%d\n",&arr[2]);
		  printf("%d\n",&arr[3]);
		   printf("%d\n",&arr[4]);
		    printf("\n*******************************\n");
			 printf("%d\n",arr);
			  printf("%d\n",arr +1);
			    printf("%d\n",arr+2);
				 printf("%d\n",arr+3);
				  printf("%d\n",arr+4);
				   printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
				    printf("%d\n",&arr);
				 printf("%d\n",&arr+1);
			 printf("%d\n",&arr+2);
		 printf("%d\n",&arr+3);
	 printf("%d\n",&arr+4);
 printf("\n##############################################\n");
  printf("%d\n",*arr);
   printf("%d\n",*(arr+1));
    printf("%d\n",*(arr+2));
	 printf("%d\n",*(arr+3));
	  printf("%d\n",*(arr+4));
	   printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	   printf("%d\n",*(&arr[0]));
	    printf("%d\n",*(&arr[1]));
		 printf("%d\n",*(&arr[2]));
		  printf("%d\n",*(&arr[3]));
		   printf("%d\n",*(&arr[4]));
		    printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");	
			
			//Error occurs [arr++ or arr--]
			//Valit int *arrptr=arr
			//Valid arrptr++ or arrptr-- 	 	 	 	 

 return 0;}

