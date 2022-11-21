#include<stdio.h>
#include<string.h>
int main ()
{    int T,i,j,k;

    scanf("%d",&T);

    int N[T],K[T],sum[T],o[T];

    for(i=0;i<T;i++){
        scanf("%d %d",&N[i],&K[i]);

        sum[i]=0;

        char s[N[i]];

        scanf("%s",&s);

        for(j=0;j<N[i];j++){
            if(j>=0 && j<=(N[i]/2)-1){
                if(s[j]!=s[N[i]-j-1]){
                    sum[i]++;
                } } }
        if(sum[i]==K[i]){
            o[i]=0;
        }
        else if (sum[i]>K[i]){
            o[i]=sum[i]-K[i];
        }
        else if (K[i]>sum[i]){
            o[i]=K[i]-sum[i];
        }
    }

    for(i=0;i<T;i++){
        printf("Case #%d: %d\n",i+1,o[i]);
    }
  return 0;
}
