#include<stdio.h>
#include<math.h>
#include<string.h>

 int main(){
  int yr1,yr2,diff,t_day,lpyr=0;
  printf("Taking reference year is \"2001(01-01-01)\" and Starting day \"MONDAY\" \n");
  yr1=2001;
  printf("Enter required year to find starting day = ");
  scanf("%d",&yr2);
  
  diff=yr2 - yr1;
  while(yr1<yr2){
  if(yr1%100==0){
  	if(yr1%400==0){
  		lpyr++;
	  }
  }
  else {
  	if(yr1%4==0){
  		lpyr++;
	  }
  }
  yr1++;}
  
  t_day=(diff-lpyr)*365 + lpyr*366;
  int day=t_day%7;
  
  printf("The first day of the year %d ...\n",yr2);
  switch(day){
  	case 0 : printf("\t\t MONDAY");  break;
  	case 1 : printf("\t\t TUESDAY");  break;
  	case 2 : printf("\t\t WEDNESDAY");  break;
  	case 3 : printf("\t\t THURSDAY");  break;
  	case 4 : printf("\t\t FRIDAY");  break;
  	case 5 : printf("\t\t SATURDAY");  break;
  	case 6 : printf("\t\t SUNNDAY");  break;
  }

 return 0;}

