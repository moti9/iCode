#include<bits/stdc++.h>

using namespace std;

int main ()
{
     short t;
     cin>>t;
     for(int j=0;j<t;j++)
     {
         string x,y;
         cin>>x;
         getchar();
         cin>>y;
         getchar();
        int i;
         for(i=0;i<x.length();i++)
         {
             if(x[i]==y[i])
             {
                 continue;
             }
             else if ( (x[i]=='?') && (y[i]!='?') || (x[i]!='?') && (y[i]=='?') )
             {
                 continue;
             }
             else if( x[i]=='?' && y[i]=='?' )
             {
                 continue;
             }
             else 
             {
                 break;
             }
         }
         if(i==x.length())
         {
             cout<<"Yes"<<endl;
         }
         else
         {
             cout<<"No"<<endl;
         }
     }
  return 0;
}
