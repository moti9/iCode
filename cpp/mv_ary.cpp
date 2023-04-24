#include<stdio.h>
int main(void){
	int Array[10]={ 1,4,7,2,5,8,0,3,6,9};
	for(int i=0;i<10;i++){
		printf("%d-[%d]\n",i+1,Array[i]);
	}
}
