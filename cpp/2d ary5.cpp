#include<stdio.h>
int main(void)
{ int i,n,temp;
printf("Enter required number in an Array=");
scanf("%d",&n);
int ary1[n];
for(i=0;i<n;i++){
	printf("Array Element-%d=",i);
	scanf("%d",&ary1[i]);}
	
printf("Original Array:\n");
for(i=0;i<n;i++){
	printf("[%d]=%d\t",i,ary1[i]);}
int ary2[n];		
for(i=0;i<n;i++){
	temp=ary1[i];
	ary1[i]=ary2[i];
	ary2[i]=temp;}
printf("\nCopied Array from input side:\n");

for(i=0;i<n;i++)
printf("[%d]=%d\t",i,ary2[i]);		
	
}
