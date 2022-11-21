#include<stdio.h>
//function for factorial
int fact(int x){
	if(x==0 || x==1){
		return 1;}
		else{ return x * fact(x-1);}
}
//function for checking strong num
int strong_Num(int x){
	int r,sum=0,f;  
   int k=x;   
    while(k!=0)  
    {  
       // r=k%10;  
        //f=fact(k%10);  
        sum+=fact(k%10);  
        k=k/10;
    }  
    if(sum==x)  
    {  
        return k;  
    } 
}

//printing strong num in range
int p_strong(int lowerLimit, int upperLimit){
	 printf("All Strong number between %d to %d are: ", lowerLimit, upperLimit);
    while(lowerLimit <= upperLimit)
    {
        if(strong_Num(lowerLimit)){
            printf("%d, ", lowerLimit);
        }        
        lowerLimit++;}}
//main function
int main()
{   int lowerLimit, upperLimit;
    
    printf("Enter the lower and upper limit to list Strong number: ");
    scanf("%d%d", &lowerLimit, &upperLimit);
    // function calling
        p_strong(lowerLimit, upperLimit);
        return 0;
}

//Need to update
