#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int countStudents(vector<int> &pages, int n, int page)
    {
        int students = 1;
        long long allocated = 0;
        for (int i = 0; i < n; i++)
        {
            if (allocated + pages[i] <= page)
            {
                allocated += pages[i];
            }
            else
            {
                allocated = pages[i];
                students += 1;
            }
        }
        return students;
    }

public:
    int findPages(vector<int> &pages, int n, int m)
    {
        if (m > n)
        {
            return -1;
        }
        int low = *max_element(pages.begin(), pages.end());
        int high = accumulate(pages.begin(), pages.end(), 0);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int students = countStudents(pages, n, mid);
            if (students > m)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> pages(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    int students;
    cin >> students;

    Solution sol;
    cout << sol.findPages(pages, n, students) << endl;

    return 0;
}