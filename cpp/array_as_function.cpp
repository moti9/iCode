#include<stdio.h>
int func1(int array[]){
	for(int i=0;i<5;i++){
		printf("The value at \"%d\" is %d\n",i,array[i]);
	}
	array[2]=6381;//if we change the value..then it will be reflected in main().
return 0;}
int func2(int *ptr){
	for(int i=0;i<5;i++){
		printf("The value at \"%d\" is %d \n",i,*(ptr+i));
	}
	*(ptr+3)=8163;
return 0;}
int func3(int arry[2][2]){
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("The value at \"%d\" , \"%d\" is  %d \n",i,j,arry[i][j]);
		}
	}
return 0;}

 int main(){
  int arr[]={1,2,3,4,5};
  int arr1[2][2]={{1,2},{4,5}};
  printf(".............Stage func1...........\n");
  printf("The value at index 2 is %d\n",arr[2]);
  func1(arr);
  printf("The value at index 2 is %d\n",arr[2]);
  printf("\n**********....Stage func2....**********\n");
  func2(arr);
  printf("\n............................\n");
  func2(arr);
  printf("\n++++++....Stage func3........+++++++++\n");  
  func3(arr1);

 return 0;}

