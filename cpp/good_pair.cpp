#include<bits/stdc++.h>
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       #define s second
        #define f first
        int x,c=0;
        unordered_map<int, int> mp;
        for(auto i: mp) mp[i]++;
        for(auto &i: mp)
            x=i.s;
        if(x>i)
            c=c+ x*(x-1)/2;
        return c;
        
    }
    
};
int main()
{  int nums = {1,2,3,1,1,3};
  cout<<numIdenticalPairs(vector<int>& nums);


return 0;}

