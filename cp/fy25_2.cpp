#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class HashGenerator
{
    unordered_map<char, int> charMap;

public:
    HashGenerator()
    {
        int value = 0;
        char character = 'a';

        while (character != 'z')
        {
            charMap[character] = value++;
            character++;
        }

        charMap['z'] = 25;
        charMap[':'] = 26;
        charMap['/'] = 27;
        charMap['.'] = 28;
    }

    string findHashedUrl(const string &url, const string &hashString, int k)
    {
        string result = "";

        int m = hashString.size();

        for (size_t i = 0; i < url.size(); i += k)
        {
            string substring;
            if (i + k - 1 <= url.size())
                substring = url.substr(i, k);
            else
                substring = url.substr(i, url.size() - i + 1);

            int value = findHashValue(substring) % m;
            result += (hashString[value]);
        }

        return result;
    }

private:
    int findHashValue(const string &str)
    {
        int result = 0;

        for (char ch : str)
        {
            result += charMap[ch];
        }

        return result;
    }
};

string getHashedURL(string url, string hash_string, int k)
{
    HashGenerator hashGenerator;
    return hashGenerator.findHashedUrl(url, hash_string, k);
}

int main()
{

    cout << getHashedURL("https://xyz.com", "pqrst", 4) << endl;

    return 0;
}
