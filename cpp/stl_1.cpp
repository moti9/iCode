#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    vector<int> vec = {63, 81, 3, 6, 8, 1};
    //cout<<vec[1]<<endl;
    sort(vec.begin(), vec.end());
    // sort(vec.end(),vec.begin());   // Wrong
    //cout << vec[3] << endl;

    for (auto x : vec)
        cout << x << " "; //for printing value....

    bool present = binary_search(vec.begin(), vec.end(), 63); //true
    present = binary_search(vec.begin(), vec.end(), 100);     //false

    vec.push_back(100);
    present = binary_search(vec.begin(), vec.end(), 100); //true

    vec.push_back(100);
    vec.push_back(100);
    vec.push_back(100);
    vec.push_back(100);
    //1,3,6,8,63,81,100,100,100,100,100

    vector<int>::iterator it = lower_bound(vec.begin(), vec.end(), 100);
    vector<int>::iterator it2 = upper_bound(vec.begin(), vec.end(), 100);
    cout << it << " "<< it2 << endl;
    cout << it2 - it << endl;

    return 0;
}
