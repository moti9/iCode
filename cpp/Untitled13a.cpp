 //13) Write a program in C to find the second smallest element in an array.
 #include<stdio.h>
int main()
{int i,ary[10],sm1,sm2;
for(i=0;i<10;i++){
    printf("Element-%d=",i);
    scanf("%d",&ary[i]);
}
if(ary[0]<ary[1]){
    sm1=ary[0];
    sm2=ary[1];
}
else{
    sm1=ary[1];
    sm2=ary[0];
}
for(i=2;i<10;i++){
    if(ary[i]<sm1){
        sm2=sm1;
        sm1=ary[i];
    }
    else if(ary[i]<sm2){
        sm2=ary[i];
    }
}
printf("The second smallest element in an Array %d",sm2);
return 0;

}
