 #include<stdio.h>
 int main(void)
 { 
     double i;
     printf("Type Number: ");
     scanf("%lf",& i);
     
     switch(i>0.0){
         
         case 1 : printf("\n Given number is positive\n"); break;
         
         case 0 :
         switch(i<0.0)
         { case 1 : printf("\n Given number is negative\n"); break;
         
         case 0 : printf("\n Given number is zero\n"); break;
         
        }  break;   }
         
     printf("\n****************************************************\n");
 }
