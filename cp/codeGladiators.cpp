#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int generateLists(const std::string &s, int start, std::unordered_map<int, int> &memo, int k)
{
    if (start >= s.length())
    {
        return 1;
    }

    // Check if the result is already memoized
    if (memo.find(start) != memo.end())
    {
        return memo[start];
    }

    int count = 0;
    // Try all possible lengths of numbers starting from the current position
    for (int length = 1; length <= s.length() - start; ++length)
    {
        std::string numStr = s.substr(start, length);
        // Check if the number has a leading zero
        if (numStr.length() > 1 && numStr[0] == '0')
            break;
        int num = std::stoi(numStr);
        if (num >= 1 && num <= k)
        {
            count += generateLists(s, start + length, memo, k);
        }
    }

    // Memoize the result
    memo[start] = count;
    return count;
}

int getCountOfAllNumberLists(const std::string &s, int k)
{
    std::unordered_map<int, int> memo;
    return generateLists(s, 0, memo, k);
}

int main()
{
    std::string s = "120356";
    int k = 10000;
    int count = getCountOfAllNumberLists(s, k);

    std::cout << "Count of valid lists: " << count << std::endl;

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <string>

void generateLists(const std::string &s, int start, std::vector<int> &current, int &count, int k)
{
    if (start >= s.length())
    {
        count++;
        return;
    }

    // Try all possible lengths of numbers starting from the current position
    for (int length = 1; length <= s.length() - start; ++length)
    {
        std::string numStr = s.substr(start, length);
        // Check if the number has a leading zero
        if (numStr.length() > 1 && numStr[0] == '0')
            break;
        int num = std::stoi(numStr);
        if (num >= 1 && num <= k)
        {
            current.push_back(num);
            generateLists(s, start + length, current, count, k);
            current.pop_back();
        }
    }
}

int getCountOfAllNumberLists(const std::string &s, int k)
{
    int count = 0;
    std::vector<int> current;
    generateLists(s, 0, current, count, k);
    return count;
}

int main()
{
    std::string s = "1203";
    int k = 10000;
    int count = getCountOfAllNumberLists(s, k);

    std::cout << "Count of valid lists: " << count << std::endl;

    return 0;
}
*/

/*

#include <iostream>
#include <vector>
#include <string>

void generateLists(const string &s, int start, vector<int> &current, vector<vector<int>> &result, int k)
{
    if (start >= s.length())
    {
        result.push_back(current);
        return;
    }

    // Try all possible lengths of numbers starting from the current position
    for (int length = 1; length <= s.length() - start; ++length)
    {
        string numStr = s.substr(start, length);
        // Check if the number has a leading zero
        if (numStr.length() > 1 && numStr[0] == '0')
            break;
        int num = stoi(numStr);
        if (num >= 1 && num <= k)
        {
            current.push_back(num);
            generateLists(s, start + length, current, result, k);
            current.pop_back();
        }
    }
}

vector<vector<int>> getAllNumberLists(const string &s, int k)
{
    vector<vector<int>> result;
    vector<int> current;
    generateLists(s, 0, current, result, k);
    return result;
}

int main()
{
    string s = "123056";
    int k = 100;
    vector<vector<int>> lists = getAllNumberLists(s, k);

    // Print the generated lists
    if (lists.empty())
    {
        cout << "[] (Not possible)" << endl;
    }
    else
    {
        for (const auto &list : lists)
        {
            cout << "[";
            for (int i = 0; i < list.size(); ++i)
            {
                cout << list[i];
                if (i != list.size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
    }

    return 0;
}
*/

/*

#include <iostream>
#include <vector>
#include <string>

void generateLists(const string &s, int start, vector<int> &current, vector<vector<int>> &result, int k)
{
    if (start >= s.length())
    {
        result.push_back(current);
        return;
    }

    // Try all possible lengths of numbers starting from the current position
    for (int length = 1; length <= s.length() - start; ++length)
    {
        int num = stoi(s.substr(start, length));
        if (num >= 1 && num <= k)
        {
            current.push_back(num);
            generateLists(s, start + length, current, result, k);
            current.pop_back();
        }
    }
}

vector<vector<int>> getAllNumberLists(const string &s, int k)
{
    vector<vector<int>> result;
    vector<int> current;
    generateLists(s, 0, current, result, k);
    return result;
}

int main()
{
    string s = "1203";
    int k = 3;
    vector<vector<int>> lists = getAllNumberLists(s, k);

    // Print the generated lists
    for (const auto &list : lists)
    {
        cout << "[";
        for (int i = 0; i < list.size(); ++i)
        {
            cout << list[i];
            if (i != list.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <string>

void generateLists(const string &s, int start, vector<int> &current, vector<vector<int>> &result)
{
    if (start >= s.length())
    {
        result.push_back(current);
        return;
    }

    // Try all possible lengths of numbers starting from the current position
    for (int length = 1; length <= s.length() - start; ++length)
    {
        int num = stoi(s.substr(start, length));
        current.push_back(num);
        generateLists(s, start + length, current, result);
        current.pop_back();
    }
}

vector<vector<int>> getAllNumberLists(const string &s)
{
    vector<vector<int>> result;
    vector<int> current;
    generateLists(s, 0, current, result);
    return result;
}

int main()
{
    string s = "12034";
    vector<vector<int>> lists = getAllNumberLists(s);

    // Print the generated lists
    for (const auto &list : lists)
    {
        cout << "[";
        for (int i = 0; i < list.size(); ++i)
        {
            cout << list[i];
            if (i != list.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
*/