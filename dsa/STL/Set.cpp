#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

# Def :: A set in STL is a container that stores unique elements in a particular order. Every operation on a set takes O(1) complexity in the average case and takes O(n) in the worst case.

# Syntax :: set<object_type> variable_name;

# Example ::
    set<int> s;
    set<string> str;

# Functions in set ::
=>  insert() – to insert an element in the set.
    set<int> s;
    s.insert(1);
    s.insert(2);

=>  begin() – return an iterator pointing to the first element in the set.
    s.begin();

=>  end() – returns an iterator to the theoretical element after the last element.
    s.end();

=>  count() – returns true or false based on whether the element is present in the set or not.
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.count(2); //returns true

=>  clear() – deletes all the elements in the set.
    s.clear();

=>  find() – to search an element in the set.
    set<int> s;
    s.insert(1);
    s.insert(2);
    if(s.find(2)!=s.end())
    {
        cout<<"true"<<endl;
    }

=>  erase() – to delete a single element or elements between a particular range.
    s.erase();

=>  size() – returns the size of the set.
    s.size();

=>  empty() – to check if the set is empty or not.
    s.empty();

# Other functions ::
=>  cbegin() – it refers to the first element of the set.
=>  cend() – it refers to the theoretical element after the last element of the set.
=>  rbegin() – it points to the last element of the set.
=>  rend() – it points to the theoretical element before the first element of the set.
=>  bucket_size() – gives the total number of elements present in a specific bucket in a set.
=>  emplace() – to insert an element in the set.
=>  max_size() – the maximum elements a set can hold.
=>  max_bucket_count() – to check the maximum number of buckets a set can hold.

*/

template <typename T>
void printSet(set<T> &st)
{
    cout << "Elements present in the set: ";
    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    set<int> st;
    for (int i = 1; i <= 10; i++)
    {
        st.insert(i);
    }

    printSet(st);

    int n = 2;
    if (st.find(2) != st.end())
    {
        cout << n << " is present in set" << endl;
    }

    st.erase(st.begin());
    cout << "Elements after deleting the first element.";
    printSet(st);

    cout << "The size of the set is: " << st.size() << endl;

    if (st.empty() == false)
    {
        cout << "The set is not empty " << endl;
    }
    else
    {
        cout << "The set is empty" << endl;
    }

    st.clear();
    cout << "Size of the set after clearing all the elements: " << st.size() << endl;

    return 0;
}