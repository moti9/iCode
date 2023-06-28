#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

# Def :: Vectors in STL are basically dynamic arrays that have the ability to change size whenever elements are added or deleted from them.Vector elements can be easily accessed and traversed using iterators.A vector stores elements in contiguous memory locations.

# Syntax :: vector<object_type> variable_name;

# Example ::
    vector<int> v1;
    vector<char> v2;
    vector<string> v3;

# Most used functions in Vector :
=>  begin() – it returns an iterator pointing to the first element of the vector.
    auto iterator = itr;
    itr = v1.begin();

=>  end() – it returns an iterator pointing to the element theoretically after the last element of the vector.
    auto iterator = itr;
    itr = v1.end();

=>  push_back() – it accepts a parameter and insert the element passed in the parameter in the vectors, the element is inserted at the end.
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);

=>  insert() – it is used to insert an element at a specified position.
    auto it = v1.begin();
    v1.insert(it, 5); // inserting 5 at the beginning

=>  erase() – it is used to delete a specific element.
    vector<int> v1;
    auto it = v1.begin();
    v1.erase(it); // erasing the first element

=>  pop_back() – it deletes the last element and returns it to the calling function.
    v1.pop_back();

=> front() – it returns a reference to the first element of the vector.
    v1.front();

=>  back() – it returns a reference to the last element of the vector.
    v1.back();

=>  clear() – deletes all the elements from the vector.
    v1.clear();
=>  empty() – to check if the vector is empty or not .
    v1.empty();
=>  size() – returns the size of the vector
    v1.size();

#   Other Functions ::
=>  cbegin() – it refers to the first element of the vector.
=>  cend() – it refers to the theoretical element after the last element of the vector.
=>  rbegin() – it points to the last element of the vector.
=>  rend() – it points to the theoretical element before the first element of the vector.
=>  crbegin() – it refers to the last element of the vector.
=>  crend() – it refers to the theoretical element before the first element of the vector.
=>  max_size() – returns the maximum size the vector can hold.
=>  capacity() – it returns the current capacity of the vector.

*/

template <typename T>
void printVector(vector<T> &vec)
{
    cout << "The elements in the vector: ";
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i); // inserting elements in the vector
    }

    printVector(v);

    cout << "The front element of the vector: " << v.front() << endl;
    cout << "The last element of the vector: " << v.back() << endl;
    cout << "The size of the vector: " << v.size() << endl;
    cout << "Deleting element from the end: " << v[v.size() - 1] << endl;
    v.pop_back();

    cout << "Printing the vector after removing the last element" << endl;
    printVector(v);

    cout << "Inserting 5 at the beginning:" << endl;
    v.insert(v.begin(), 5);
    printVector(v);

    cout << "The first element is: " << v[0] << endl;
    cout << "Erasing the first element" << endl;

    v.erase(v.begin());
    cout << "Now the first element is: " << v[0] << endl;

    if (v.empty())
    {
        cout << "vector is empty" << endl;
    }
    else
    {
        cout << "vector is not empty" << endl;
    }

    v.clear();
    cout << "Size of the vector after clearing the vector: " << v.size() << endl;

    vector<char> vc;
    for (int i = 0; i < 6; i++)
    {
        vc.push_back('A' + rand() % 26);
    }
    printVector(vc);

    vector<string> str;
    for (int i = 1; i <= 6; i++)
    {
        string s = to_string(96 + rand() % i);
        str.push_back(s);
    }
    printVector(str);

    return 0;
}