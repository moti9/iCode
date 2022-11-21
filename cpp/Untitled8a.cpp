//8) Write a program in C to copy the elements of one array into another array.
 #include<stdio.h>
 int main(void)
 {  int i,ary1[10],ary2[10];
 for(i=0;i<10;i++){
 	printf("Element-%d: ",i);
 	scanf("%d",& ary1[i]);   }
 	
 	for(i=0;i<10;i++){
 		ary2[i]=ary1[i]; 	 }
 		
 	printf("\nThe elements stored in the first array are :\n");
    for(i=0;i<10;i++)    {
        printf("% 5d", ary1[i]);      }
	printf("\nThe elements copied in the Second array are :\n");
    for(i=0;i<10;i++)    {
        printf("% 5d", ary2[i]);      }

 }
