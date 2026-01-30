#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
using namespace std;

#define MOD 1000000007

vector<string> split_into_words(string s) {
    vector<string> words;
    stringstream str_stm(s);
    string word;

    while (str_stm >> word) {
        words.push_back(word);
    }
    return words;
}

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<string> words(n);
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    int line_chars = 0;
    string line_str = "";
    for (const string& word : words) {
        if (line_chars + word.length() <= k) {
            if (line_chars > 0) {
                line_str += " ";
            }
            line_str += word;
            line_chars += word.length();
        } else {
            cout << line_str << "\n";
            line_str = word;
            line_chars = word.length();
        }
    }

    if (!line_str.empty()) {
        cout << line_str;
    }

    return 0;
}