#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to calculate 2px mod 2q
long long calculate_g(long long p, long long q, long long x)
{
    return (2 * p * x) % (2 * q);
}

int main()
{
    long long a, b, p, q;
    cin >> a >> b >> p >> q;

    long long t = sqrt(b - a + 1);
    vector<pair<long long, long long>> candidates;

    // Create the list of (g(x), x) pairs
    for (long long x = a; x <= a + t - 1; ++x)
    {
        candidates.emplace_back(calculate_g(p, q, x), x);
    }

    // Sort the list
    sort(candidates.begin(), candidates.end());

    long long result_x = a;
    long long closest_difference = abs(q - 2 * p * a % (2 * q));

    // Perform binary search and brute force
    for (long long i = 0; i * t <= b - a; ++i)
    {
        long long target = (q - 2 * i * t * p) % (2 * q);

        // Find the closest value to the target using binary search
        auto it = lower_bound(candidates.begin(), candidates.end(), make_pair(target, -1LL));
        if (it != candidates.end())
        {
            long long x_candidate = it->second;
            long long difference = abs(q - 2 * p * x_candidate % (2 * q));

            if (difference < closest_difference)
            {
                closest_difference = difference;
                result_x = x_candidate;
            }
        }

        // Update candidates list for the next iteration
        candidates.emplace_back(calculate_g(p, q, a + (i + 1) * t), a + (i + 1) * t);
    }

    // Brute force for remaining range
    for (long long x = max(a + t, result_x - t); x <= b; ++x)
    {
        long long difference = abs(q - 2 * p * x % (2 * q));
        if (difference < closest_difference)
        {
            closest_difference = difference;
            result_x = x;
        }
    }

    cout << result_x << endl;

    return 0;
}
