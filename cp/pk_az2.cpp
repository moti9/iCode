#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int calculateMinimumSwaps(vector<int>& fileSize, vector<int>& affinity) {
    int n = fileSize.size();
    vector<int> conflicts;
    unordered_map<int,int> countFile, countAffinity;
    
    // Count frequencies
    for (int i = 0; i < n; i++) {
        countFile[fileSize[i]]++;
        countAffinity[affinity[i]]++;
        if (fileSize[i] == affinity[i]) {
            conflicts.push_back(i);
        }
    }
    
    int c = conflicts.size();
    if (c == 0) return 0; // already safe
    
    // Feasibility check
    for (auto &p : countFile) {
        int val = p.first, cnt = p.second;
        if (cnt > n - countAffinity[val]) {
            return -1;
        }
    }
    
    // Check if all conflicts are same value
    bool allSame = true;
    for (int i = 1; i < c; i++) {
        if (fileSize[conflicts[i]] != fileSize[conflicts[0]]) {
            allSame = false;
            break;
        }
    }
    
    if (!allSame) {
        // We can pair conflicts → ceil(c/2)
        return (c + 1) / 2;
    } else {
        // All conflicts are same value
        // Need at least one safe position to swap with
        if (c < n) return c; // use safe element
        else return -1;      // all positions are conflicts → impossible
    }
}







// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// int calculateMinimumSwaps(const vector<int> &fileSize, const vector<int> &affinity) {
//     int n = (int)fileSize.size();
//     // freq maps
//     unordered_map<long long,int> cntFile, cntAff;
//     cntFile.reserve(n*2);
//     cntAff.reserve(n*2);

//     vector<int> conflictsIdx;
//     conflictsIdx.reserve(n);

//     for (int i = 0; i < n; ++i) {
//         cntFile[fileSize[i]]++;
//         cntAff[affinity[i]]++;
//         if (fileSize[i] == affinity[i]) conflictsIdx.push_back(i);
//     }

//     int k = (int)conflictsIdx.size();
//     if (k == 0) return 0;

//     // Feasibility: for every value v, c_v + m_v <= n
//     for (const auto &p : cntFile) {
//         long long v = p.first;
//         long long c = p.second;
//         long long m = cntAff.count(v) ? cntAff[v] : 0;
//         if (c + m > n) return -1;
//     }
//     // Also need to check values that appear only in affinity but not in fileSize
//     for (const auto &p : cntAff) {
//         long long v = p.first;
//         if (!cntFile.count(v)) {
//             long long c = 0;
//             long long m = p.second;
//             if (c + m > n) return -1; // this is only possible if m>n but safe to include
//         }
//     }

//     // Count conflicts per value
//     unordered_map<long long,int> conflictCount;
//     conflictCount.reserve(k*2);
//     int maxcnt = 0;
//     for (int idx : conflictsIdx) {
//         long long v = fileSize[idx];
//         int cc = ++conflictCount[v];
//         if (cc > maxcnt) maxcnt = cc;
//     }

//     // max pairs of conflicts with different values
//     int pairs = min(k / 2, k - maxcnt);
//     int minSwaps = k - pairs;
//     return minSwaps;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> fileSize(n), affinity(n);
    for (int i = 0; i < n; ++i) cin >> fileSize[i];
    for (int i = 0; i < n; ++i) cin >> affinity[i];

    cout << calculateMinimumSwaps(fileSize, affinity) << '\n';
    return 0;
}
