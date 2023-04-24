#include<stdio.h> 
int main()
{
 int arr[5] = {200,100,300,12,56};
 int first = 0;
 int last = 4;
 int temp;
 while(first < last)
 {
  arr[first]  = arr[first] + arr[last];
  arr[last] = arr[first] - arr[last];
  arr[first] = arr[first] - arr[last];  
  first ++;
  last --;
 }
 for(int i = 0; i < 5; i++)
 {
  printf("%d\n", arr[i]);
 } return 0;
}
