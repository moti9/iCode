#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
    Given a list of char with space. The complete consecutive chars (without space) make word.
    your task is to reverse the words of the arr. Lets take an example for more clearance -

    For example:
    arr = [
        'a', 'b', 'c', ' ', 'd', 'e', ' ','f', 'g', 'h', 'i'
    ]
    ans = [
        'f', 'g', 'h', 'i','d', 'e', ' ', a', 'b', 'c'
    ]
*/

vector<char> reverseWords(const vector<char> &arr)
{
    // Reverse the entire list of characters
    vector<char> ans(arr.rbegin(), arr.rend());

    int start = 0;
    int end = 0;
    while (end < ans.size())
    {
        // Find the start and end indices of each word
        while (end < ans.size() && ans[end] != ' ')
            end++;

        // Reverse the word
        reverse(ans.begin() + start, ans.begin() + end);

        // Move to the next word
        start = end + 1;
        end = start;
    }
    return ans;
}

int main()
{

    vector<char> arr = {'a', 'b', 'c', ' ', 'd', 'e', 'f', ' ', 'g', 'h', 'i', 'j'};

    vector<char> ans = reverseWords(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}