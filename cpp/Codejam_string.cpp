#include<stdio.h>
#include<string.h>

int main (){
    int T,i,j;

    scanf("%d",&T);

    int X,Y,sum[T];
	char S[1000];

    for(i=0;i<T;i++){ sum[i]=0;
        scanf("%d %d %s",&X,&Y,&S);
          for(j=0;S[j]!='\0';j++){
            if(S[j]=='C' && S[j+1]=='J' || S[j]=='C' && S[j+1]=='?' && S[j+2]=='J'){
                sum[i]=sum[i]+X;       }
            else if(S[j]=='J' && S[j+1]=='C' ||S[j]=='J' && S[j+1]=='?' && S[j+2]=='C'){
                sum[i]=sum[i]+Y;}
        }
     }
     for(i=0;i<T;i++){
         printf("Case #%d: %d\n",i+1,sum[i]);}

    return 0;
}
