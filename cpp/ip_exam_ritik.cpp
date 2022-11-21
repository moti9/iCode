#include<stdio.h>
#include<math.h>

int odd(int);

int main (){
    int n,x;

    printf("enter no.");
    scanf("%d",&n);

    x=odd(n);

    printf("%d",x);

    return 0;}

int odd(int n){
    int r,i,j=0,no;
    for(i=1;i>=1;i=n){
        r=n%10;
        n=n/10;
        if(r%2!=0){
            no=no+r*pow(10,j);
            j++;}}
    no=no*10;
    return no;
}
