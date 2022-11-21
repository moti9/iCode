#include<stdio.h>

 int main(){
  int x,y;
  printf("Ajay's salary = ");
  scanf("%d",&x);
  printf("Sumit's salary = ");
  scanf("%d",&y);
  float Mean=1.0*(x+y)/2;
  int Mod=x%y;
  printf("Mean of Ajay and Sumit's Salary = %f \n",Mean);
  printf("Mod of Ajay and Sumit salary = %d ",Mod);
 return 0;}

