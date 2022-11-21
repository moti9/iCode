#include<stdio.h>
int main(void)
{ int i;

printf("Type number 1-7\n");
printf("Choose Number: ");
scanf("%d",& i);

switch(i){
	case 1 : printf("\n Monday \n");  break;
	case 2 : printf("\n Tuesday \n");  break;
	case 3 : printf("\n Wednesday \n");  break;
	case 4 : printf("\n Thursday \n");  break;
	case 5 : printf("\n Friday \n");  break;
	case 6 : printf("\n Saturday \n");  break;
	case 7 : printf("\n Sunday \n");  break;
	default : printf("\n Error ! Choosen wrong choice \n");  }
	
	printf("\n**********************************************\n");
	
}
