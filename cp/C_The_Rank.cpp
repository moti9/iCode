#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class solution
{
    struct Student
    {
        int id;
        int totalScore;

        bool operator<(const Student &other) const
        {
            if (totalScore == other.totalScore)
            {
                return id > other.id;
            }
            return totalScore < other.totalScore;
        }
    };

public:
    solution()
    {
        int n;
        cin >> n;

        priority_queue<Student> pq;

        for (int i = 1; i <= n; ++i)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            int total = a + b + c + d;
            pq.push({i, total});
        }

        int rank = 1;
        while (!pq.empty())
        {
            Student topStudent = pq.top();
            pq.pop();
            if (topStudent.id == 1)
            {
                cout << rank << endl;
                break;
            }
            rank++;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll ttt = 1;
    // cin>>ttt;
    while (ttt--)
    {
        solution moti;
    }
    return 0;
}
