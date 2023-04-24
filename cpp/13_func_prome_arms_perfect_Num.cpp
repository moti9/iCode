#include<stdio.h>
#include<math.h>

int prime_Num(int num){
	int i,flag;
	for(i=2;i<=num/2;i++){
		if(num%i==0){
			flag=0;}
		else {flag=1;
		}	
			}
		return flag;
}
int armstrong_Num(int num){
	
   int orgNum, remd, n = 0, flag;
   double result = 0.0;

   for (orgNum=num;orgNum!=0;n++) {
      orgNum /= 10;
   }

   for (orgNum = num; orgNum != 0; orgNum /= 10) {
      remd = orgNum % 10;
      result += pow(remd, n);}

   if (round(result) == num)
      flag = 1;
   else
      flag = 0;
   return flag;
}

int perfect_Num(int num){
	int i,Sum = 0,flag;   
 
 	for(i=1;i<num; i++){
  		if(num % i == 0)
		    Sum = Sum + i ;   
  	}    
  	if(Sum == num){flag=1; 
	  }    
 	else{flag=0; 
	 }   
   return flag; 	  
}


int main()
{    int num,flag;
    
    printf("Enter any number: ");
    scanf("%d", &num); 
    flag = prime_Num(num);
    if(flag==1)
    {
        printf("%d is Prime number.\n", num);
    }
    else
    {
        printf("%d is not Prime number.\n", num);
    }
    
    flag = armstrong_Num(num);
    if(flag==1)
    {
        printf("%d is Armstrong number.\n", num);
    }
    else
    {
        printf("%d is not Armstrong number.\n", num);
    }
    
    flag = perfect_Num(num);
    if(flag==1)
    {
        printf("%d is Perfect number.\n", num);
    }
    else
    {
        printf("%d is not Perfect number.\n", num);
    }
    printf("\n******************************************\n");
    return main();
}

