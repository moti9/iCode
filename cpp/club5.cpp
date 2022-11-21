#include<stdio.h>

int xorOperation(int n, int start){
    int a[n];
  for(int i=0;i<n;i++){
       a[i]=start+(2*i);      
  }
    int num=0;
    for(int i=0;i<n;i++){
       num=num^a[i];      
  }
    return num;
}

int main(){
    int n,start;
    scanf("%d %d",&n,&start);
    int result=xorOperation(n,start);
    printf("%d",result);
}
