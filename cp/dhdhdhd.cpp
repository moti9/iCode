#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int numOfMembers, numOfActivities, numOfHours;
    cin >> numOfMembers >> numOfActivities >> numOfHours;

    vector<vector<int>> activity_counts(numOfActivities + 1, vector<int>(numOfMembers + 1, 0));

    for (int i = 1; i <= numOfHours; i++)
    {
        int first, last, activityType;
        cin >> first >> last >> activityType;

        for (int j = first; j <= last; j++)
        {
            activity_counts[activityType][j]++;
        }

        for (int k = 0; k <= numOfActivities; k++)
        {
            int max_count = 0;
            for (int j = 1; j <= numOfMembers; j++)
            {
                max_count = max(max_count, activity_counts[k][j]);
            }
            cout << max_count << " ";
        }
        cout << endl;

        for (int k = 0; k <= numOfActivities; k++)
        {
            for (int j = 1; j <= numOfMembers; j++)
            {
                activity_counts[k][j] = 0;
            }
        }
    }
    return 0;
}
    // #include <bits/stdc++.h>
    // using namespace std;
    // #define ll long long
    // #define mod 1000000007

    // void arrayReverse(int len, int *arr)
    // {
    //     int i, temp, originalten = len;
    //     for (i = 0; i < originalten/2; i++)
    //     {
    //         temp = arr[len - 1];
    //         arr[len - 1] = arr[i];
    //         arr[i] = temp;
    //         len -= 1;
    //     }
    // }

    // int main()
    // {
    //     int arr[] = {1, 5, 8, 9};
    //     arrayReverse(4, arr);
    //     for (int i = 0; i < 4; i++)
    //     {
    //         cout << arr[i] << " ";
    //     }

    //     return 0;
    // }