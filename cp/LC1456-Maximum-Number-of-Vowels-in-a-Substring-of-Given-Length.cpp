#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
class Solution {
    int cntvowels(string &s){
        int vowels=0;
        for(auto c:s){
           if(c=='a' || c=='i' || c=='e'|| c=='o' || c=='u'){
                vowels+=1;
            } 
        }
        return vowels;
    }
public:
    int maxVowels(string s, int k) {
        int ans=0;
        string st=s.substr(0,k);
        int vowels=cntvowels(st);
        ans=max(ans,vowels);
        int n=s.length();
        for(int i=0,j=k;i<=n-k && j<n;i++,j++){
            if(s[i]=='a' || s[i]=='i' || s[i]=='e'|| s[i]=='o' || s[i]=='u'){
                vowels-=1;
            } 
            if(s[j]=='a' || s[j]=='i' || s[j]=='e'|| s[j]=='o' || s[j]=='u'){
                vowels+=1;
            } 
            ans=max(ans,vowels);
        }
        return ans;
    }
};

*/
class Solution
{
    bool isvowel(char &c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:

    int maxVowels(string s, int k)
    {
        int ans = 0;
        int cntvowels = 0;
        for (int i = 0; i < k; i++)
        {
            cntvowels += isvowel(s[i]);
        }
        ans = max(ans, cntvowels);
        int n = s.length();
        for (int i = k; i < n; i++)
        {
            cntvowels += isvowel(s[i]) - isvowel(s[i - k]);
            ans = max(ans, cntvowels);
        }
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    Solution sol;

    cout << sol.maxVowels(s, k) << endl;

    return 0;
}