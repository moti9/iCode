#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
# Def :: An unordered_multiset in STL is an associative container just like an unordered set the only difference is it can store duplicate elements in it.

# Syntax :: unordered_multiset<object_type> variable_name;

# Example ::
    unordered_multiset<int> s;
    unordered_multiset<string> str;

# Functions in multiset ::

=>  insert() – to insert an element in the unordered multiset.
    unordered_multiset<int> s;
    s.insert(1);
    s.insert(2);

=>  begin() – return an iterator pointing to the first element in the unordered multiset.
    s.begin();

=>  end() – returns an iterator to the theoretical element after the last element.
    s.end();

=>  count() – gives the count of a particular element in the unordered multiset.
    unordered_multiset<int> s;
    s.insert(1);
    s.insert(2);
    s.count(2); //returns 1

=>  clear() – deletes all the elements in the unordered multiset.
    s.clear();

=>  find() – to search an element in the unordered multiset.
    unordered_multiset<int> s;
    s.insert(1);
    s.insert(2);
    if(s.find(2)!=s.end())
    {
        cout<<"true"<<endl;
    }

=>  erase() – to delete a single element or elements between a particular range.
    s.erase();
=>  size() – returns the size of the unordered multiset.
    s.size();

=>  empty() – to check if the unordered multiset is empty or not.
    s.empty();

# Other functions ::

=>  cbegin() – it refers to the first element of the unordered multiset.
=>  cend() – it refers to the theoretical element after the last element of the unordered multiset.
=>  rbegin() – it points to the last element of the unordered multiset.
=>  rend() – it points to the theoretical element before the first element of the unordered multiset.
=>  emplace() – to insert an element in the unordered multiset.
=>  max_size() – the maximum elements an unordered multiset can hold.
*/

template <typename T>
void printMultiSet(unordered_multiset<T> &ums)
{
    cout << "Elements present in the unordered multiset: ";
    for (auto it = ums.begin(); it != ums.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    unordered_multiset<int> ums;
    for (int i = 1; i <= 10; i++)
    {
        ums.insert(i);
    }
    ums.insert(5);

    printMultiSet(ums);

    int n = 2;
    if (ums.find(2) != ums.end())
        cout << n << " is present in unorderd multiset." << endl;

    ums.erase(ums.begin());
    cout << "Elements after deleting the first element." << endl;
    printMultiSet(ums);

    cout << "The size of the unordered multiset is: " << ums.size() << endl;

    if (ums.empty() == false)
    {
        cout << "The unordered multiset is not empty." << endl;
    }
    else
    {
        cout << "The unordered multiset is empty." << endl;
    }
    ums.clear();
    cout << "Size of the unordered multiset after clearing all the elements: " << ums.size() << endl;

    return 0;
}