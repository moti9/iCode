#include<stdio.h>
int main ()
{    int n[2],a[100],b[100],i,j=0,k=0,s[4]={0,1,0,1},f=1;

    printf("enter 1st no.:");
    scanf("%d",&n[0]);

    printf("enter 2nd no.:");
    scanf("%d",&n[1]);

    for(i=1;i<=s[1];i++){
	if(n[0]%i==0&&i!=1){
            a[j]=i;
            n[0]=n[0]/i;
            s[0]=s[0]+1;
            j++;
            printf("%d\n",i);
            i=0;}
        else{continue;}
        
        s[1]=s[1]+1;
        if(n[0]==1){break;}
        else{continue;}
    }
    printf("%d\n",s[0]);
    printf("--------------------------\n");
    for(i=1;i<=s[3];i++){
        if(n[1]%i==0&&i!=1){
            b[k]=i;
            n[1]=n[1]/i;
            s[2]=s[2]+1;
            k++;
            printf("%d\n",i);
            i=0;}
        else{continue;}
        s[3]=s[3]+1;
        if(n[1]==1){break;}
        else{continue;}
    }
    printf("%d\n",s[2]);
    printf("--------------------------\n");

if (s[0]<s[2]){for(i=0;i<s[0];i++){
            for(j=0;j<s[2];j++){
                if(a[i]==b[j]){
                    printf("%d\n",a[i]);
                    f=f*a[i];
                    break;}
                else{continue;}}}
    
        printf("%d",f);}
    else{for(i=0;i<s[2];i++){
            for(j=0;j<s[0];j++){
                if(a[j]==b[i]){
                    printf("%d\n",a[j]);
                    f=f*a[j];
                    break;}}}
    }
        printf("%d",f);

    return 0;
}
