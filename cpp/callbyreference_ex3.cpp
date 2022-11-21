#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
int change_num(int address){
	address=6381;
}
 int main(){
  int a=63;
  printf("%d\n",a);
  printf("\n==========================\n");
change_num(a);
printf("\n%d\n",a);
 return 0;}
//By callByvalue we can not change value

