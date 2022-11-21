#include<stdio.h>
#include<math.h>

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
void pArmst(int lowerLimit, int upperLimit)
{    printf("All Armstrong number between %d to %d are: ", lowerLimit, upperLimit);
    while(lowerLimit <= upperLimit)
    {
        if(armstrong_Num(lowerLimit)){
            printf("%d, ", lowerLimit);
        }        
        lowerLimit++;}}

int main()
{   int lowerLimit, upperLimit;
    
    printf("Enter the lower and upper limit to list Armstrong: ");
    scanf("%d%d", &lowerLimit, &upperLimit);
    
        pArmst(lowerLimit, upperLimit);
        return 0;
}
