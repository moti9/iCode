#include<bits/stdc++.h>

using namespace std;

int main ()

{
   int t,i;
   cin>>t;
    for(i=1;i<=t;i++)
    {
        int n,j=0,k,sum=1;
        cin>>n;
        char s[n];
        cin>>s;
        cout<<"case #"<<i<<": ";
        for(k=1;k<(n/2)+1;k++)
        {

            for(j=j;j<n;j++)
            {
               if(s[j]<s[j+1]&&j+1!=n)
               {
                   cout<<sum<<" ";
                   sum++;
               }
               else
               {
                   j++;
                   cout<<sum<<" ";
                   break;
               }

            }
            sum=1;

        }
        cout<<"\n";
    }
    return 0;
}
