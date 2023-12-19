#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int solution(vector<int>& A) {
    int n = A.size();

    // dp[i] represents the maximum sum for the first i elements
    vector<int> dp(n + 1, 0);

    // Iterate over each element and update dp
    for (int i = 1; i <= n; ++i) {
        dp[i] = A[i - 1];  // Initialize dp[i] with the current element

        for (int j = i - 1; j >= 1; --j) {
            // Concatenate elements and update dp[i] if a greater sum is found
            string str1 = to_string(A[j - 1]);
            string str2 = to_string(A[i - 1]);

            if (dp[j] + stoi(str1 + str2) > dp[i]) {
                dp[i] = dp[j] + stoi(str1 + str2);
            }
        }
    }

    return dp[n];
}

int main() {
    // Examples
    vector<int> example1 = {12, 2, 3, 5, 4, 0};
    cout << "Example 1: " << solution(example1) << endl; // Output: 97

    vector<int> example2 = {3, 19, 191, 91, 3};
    cout << "Example 2: " << solution(example2) << endl; // Output: 20107

    vector<int> example3 = {12, 6, 18, 10, 1, 0};
    cout << "Example 3: " << solution(example3) << endl; // Output: 1946

    vector<int> example4 = {2, 1, 0, 1, 2, 9, 1, 0};
    cout << "Example 4: " << solution(example4) << endl; // Output: 124

    return 0;
}







// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mod 1000000007

// struct Node
// {
//     string data;
//     Node *prev, *next;

//     Node(int val)
//     {
//         data = to_string(val);
//         prev = nullptr;
//         next = nullptr;
//     }
// };

// void insertAtBegin(Node *&root, int val)
// {
//     Node *node = new Node(val);
//     if (root == nullptr)
//     {
//         root == node;
//     }
//     else
//     {
//         node->next = root;
//         root->prev = node;
//         root = node;
//     }
// }

// void merge(Node *&root)
// {
//     return;
// }

// long long solution(vector<int> &A)
// {
//     int n = A.size();
//     if (n == 1)
//     {
//         return A[0];
//     }
//     // write rest of logic
//     Node *root = new Node(A[n - 1]);
//     unordered_map<Node *, int> mp;
//     for (int i = n - 2; i >= 0; i--)
//     {
//         insertAtBegin(root, A[i]);
//     }

//     merge(root);

//     long long sum = 0;
//     Node *temp = root;
//     while (temp != nullptr)
//     {
//         sum += stoll(temp->data);
//     }
//     return sum;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     return 0;
// }