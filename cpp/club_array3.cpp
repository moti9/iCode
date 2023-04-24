#include<stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    int b[n];   //true-1  // false-0
    int count;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    for(int i=0;i<n;i++,count=0){  //i=1
        
        for(int j=0;j<n;j++){
            if(a[j]>a[i]) count++;
        }
        b[i]=count;
    }
    for(int i=0;i<n;i++) printf("%d \t",b[i]);
    return 0;
}
