#include<stdio.h>
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
int p_perfect(int lowerLimit, int upperLimit){
	 printf("All Perfect number between %d to %d are: ", lowerLimit, upperLimit);
    while(lowerLimit <= upperLimit)
    {
        if(perfect_Num(lowerLimit)){
            printf("%d, ", lowerLimit);
        }        
        lowerLimit++;}}


int main()
{   int lowerLimit, upperLimit;
    
    printf("Enter the lower and upper limit to list Perfect: ");
    scanf("%d%d", &lowerLimit, &upperLimit);
    
        p_perfect(lowerLimit, upperLimit);
        return 0;
}
