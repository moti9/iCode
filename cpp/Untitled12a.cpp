//12) Write a program in C to find the second largest element in an array. 
#include<stdio.h>
int main(void)
{ int i,ary[10],max1=0,max2=0;
for(i=0;i<10;i++){
    printf("Element-%d: ",i);
    scanf("%d",&ary[i]);}
    
    for(i=0;i<10;i++){
    if(ary[i]>max1){
        max2=max1;
        max1=ary[i];     } 
        else if(ary[i]>max2 && ary[i]<max1){
            max2=ary[i];
        }
    }

    printf("Second largest element in an Array: %d",max2);
}
