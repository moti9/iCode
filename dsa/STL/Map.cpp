#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

# Def :: Map in STL are associative containers where each element consists of a key value and a mapped value. Two mapped values cannot have the same key value.

# Syntax :: map<object_type,object_type> variable_name;

# Example ::
    map<int,int> mpp;
    map<string,int> mpp;

# Functions in map ::

=>  insert() – to insert an element in the map.
    map<int,int> mp;
    mp.insert({1,10});
    mp.insert({2,20});

=>  begin() – return an iterator pointing to the first element in the map.
    mp.begin();

=>  end() – returns an iterator to the theoretical element after the last element.
    mp.end();

=>  clear() – deletes all the elements in the map.
    mp.clear();

=>  find() – to search for an element in the map.
    map<int,int> mp;
    mp.insert({1,10});
    mp.insert({2,20});
    if(mp.find(2)!=mp.end())
    {
        cout<<"true"<<endl;
    }

=>  erase() – to delete a single element or elements between a particular range.
    mp.erase(key);
    mp.erase(iterator position);
    mp.erase(iterator position 1, iterator position 2);

=>  size() – returns the number of elements on the map.
    mp.size();

=>  empty() – to check if the map is empty or not.
    mp.empty();

# Other functions ::

=>  cbegin() – it refers to the first element of the map.
=>  cend() – it refers to the theoretical element after the last element of the map.
=>  rbegin() – it points to the last element of the map.
=>  rend() – it points to the theoretical element before the first element of the map.
=>  emplace() – to insert an element in the map.
=>  max_size() – the maximum elements a map can hold.

*/

template <typename T1, typename T2>
void printMap(map<T1, T2> &mp)
{
    cout << "Elements present in the map : " << endl;
    cout << "Key\tElement" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }
}
int main()
{
    map<int, int> mp;
    for (int i = 1; i <= 5; i++)
    {
        mp.insert({i, i * 6});
    }
    printMap(mp);

    int n = 2;
    if (mp.find(2) != mp.end())
    {
        cout << n << " is present in map." << endl;
    }

    mp.erase(mp.begin());
    printMap(mp);

    cout << "The size of the map is : " << mp.size() << endl;

    if (mp.empty() == false)
    {
        cout << "The map is not empty." << endl;
    }
    else
    {
        cout << "The map is empty." << endl;
    }
    mp.clear();
    cout << "Size of the map after clearing all the elements : " << mp.size() << endl;

    return 0;
}