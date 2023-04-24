 #include<stdio.h>
 
 int main(){
     int n;
     scanf("%d",&n);
     int nums[n],index[n];
     for(int i=0;i<n;i++) scanf("%d",&nums[i]);
     for(int i=0;i<n;i++) scanf("%d",&index[i]);
     int y,z;
         int i=0;
        while(i<n){
            if(i!=index[i]) {
                int t=i-index[i];
                y=i;
                while(t!=0){
                    z=nums[y-1];
                    nums[y-1]=nums[y];
                    nums[y]=z;  
             
                     y--;
                       t--;
                }
            }
            i++;
        }                                                                  
       for(int i=0;i<n;i++) printf("%d\t",nums[i]); 
 }
