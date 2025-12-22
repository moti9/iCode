#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.size();

        while (i < n && isspace(s[i])) i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) i++;

        bool isNumeric = false, hasDecimal = false, hasExponent = false;

        while (i < n) {
            if (isdigit(s[i])) {
                isNumeric = true;
            } else if (s[i] == '.') {
                if (hasDecimal || hasExponent) return false;
                hasDecimal = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (hasExponent || !isNumeric) return false;
                hasExponent = true;
                isNumeric = false;
                i++;
                if (i < n && (s[i] == '+' || s[i] == '-')) i++;
                continue;
            } else if (isspace(s[i])) {
                break;
            } else {
                return false;
            }
            i++;
        }

        while (i < n && isspace(s[i])) i++;

        return isNumeric && i == n;
        
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string numStr;
    cin >> numStr;

    Solution sol;
    if (sol.isNumber(numStr)) {
        cout << "Valid Number\n";
    } else {
        cout << "Invalid Number\n";
    }

    return 0;
}