#include<stdio.h>
int main(){
int i,j,k=1;
for(i=1;i<=4;i++){
for(j=1;j<=i;j++){

  printf("%d ",k++);
if(k==9) break;
}
printf("\n");
}
return 0;
} 
