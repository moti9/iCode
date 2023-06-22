#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// int distractSoldiers(std::vector<int> &soldiers)
// {
//     int count = 0; // Number of soldiers to distract
//     int n = soldiers.size();
//     int leftLooking = 0; // Number of soldiers looking towards the left

//     // Count the number of soldiers looking towards the left
//     for (int i = 0; i < n; i++)
//     {
//         if (soldiers[i] == 0)
//             leftLooking++;
//     }

//     int rightLooking = n - leftLooking; // Number of soldiers looking towards the right

//     int distractedLeft = 0;  // Number of soldiers distracted towards the left
//     int distractedRight = 0; // Number of soldiers distracted towards the right

//     // Start killing soldiers from the left side
//     for (int i = 0; i < n; i++)
//     {
//         if (soldiers[i] == 0)
//         {
//             leftLooking--;
//             if (distractedRight > 0)
//             {
//                 distractedRight--;
//             }
//             else
//             {
//                 count++;
//                 distractedLeft++;
//             }
//         }
//         else
//         {
//             rightLooking--;
//             if (distractedLeft > 0)
//             {
//                 distractedLeft--;
//             }
//             else
//             {
//                 count++;
//                 distractedRight++;
//             }
//         }

//         // All soldiers killed without alerting the royal guard
//         if (leftLooking == 0 && rightLooking == 0)
//             break;
//     }

//     return count;
// }

// int directedSoldiers(int n, std::vector<int> &a)
// {
//     int distracted = 0; // Number of distracted soldiers
//     int rightCount = 0; // Number of soldiers looking toward the right side

//     for (int i = 0; i < n; i++)
//     {
//         // If the soldier looks toward the right side, increment the count
//         if (a[i] == 1)
//         {
//             rightCount++;
//         }
//         // If the soldier looks toward the left side and there are soldiers
//         // looking toward the right side, distract one soldier
//         else if (rightCount > 0)
//         {
//             rightCount--; // Decrement the count of soldiers looking right
//             distracted++; // Increment the count of distracted soldiers
//         }
//     }

//     return distracted;
// }

int directedSoldiers(int n, vector<int> &a)
{
    int z = 0, o = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 0)
            z++;

        else
            o++;
    }

    return min(z, o);
}

int main()
{
    int n;
    cin >> n;

    vector<int> soldiers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> soldiers[i];
    }

    int minDistracted = directedSoldiers(n, soldiers);
    cout << minDistracted << endl;

    return 0;
}
