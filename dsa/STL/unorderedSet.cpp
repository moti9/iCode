#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
# Def :: An unordered set in STL is a container that stores unique elements in no particular order. Every operation on an unordered set takes O(1) complexity in the average case and takes O(n) in the worst case.

# Syntax :: unordered_set<object_type> variable_name;

# Example ::
unordered_set<int> s;
unordered_set<string> str;

# Functions in unordered_set

=>  insert() – to insert an element in the unordered set.
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);

=>  begin() - return an iterator pointing to the first element in the unordered set.
    s.begin()

=>  count() - it returns 1 if the element is present in the container otherwise 0.
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.count(2); //returns true(1)

=>  clear() – deletes all the elements in unordered set.
    s.clear();

=>  find() – to search an element in the unordered set.
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    if(s.find(2)!=s.end())
    {
        cout<<"true"<<endl;
    }

=>  erase() – to delete a single element or elements between a particular range.
    s.erase(<element>); -> To delete single element
    s.erase(<range>); -> To delete in range

=>  size() – returns the size of the unordered set.
    s.size();

=>  empty() – to check if the unordered set is empty or not.
    s.empty();
    
# Other functions ::
=>  cbegin() – it refers to the first element of the unordered set.
=>  cend() – it refers to the theoretical element after the last element of the unordered set.
=>  bucket_size() – gives the total number of elements present in a specific bucket in an unordered set.
=>  emplace() – to insert an element in the unordered set.
=>  max_size() – the maximum elements an unordered_set can hold.
=>  max_bucket_count() – to check the maximum number of buckets an unordered set can hold.

*/

template <typename T>
void printUnorderedSet(unordered_set<T> &st)
{
    cout << "Elements present in the unordered set: ";
    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    unordered_set<int> st;
    st.insert(3);
    printUnorderedSet(st);
    st.insert(6);
    st.insert(9);

    unordered_set<string> str;
    str.insert("Moti");
    printUnorderedSet(str);

    int n = 6;
    if (st.find(n) != st.end())
        cout << n << " is present in unordered set" << endl;

    st.erase(st.begin(),st.end());
    cout << "Elements after deleting the first element" << endl;
    printUnorderedSet(st);

    cout << "The size of the unordered set is: " << st.size() << endl;

    if (st.empty() == false)
        cout << "The unordered set is not empty " << endl;
    else
        cout << "The unordered set is empty" << endl;
    st.clear();
    cout << "Size of the unordered set after clearing all the elements: " << st.size() << endl;

    return 0;
}