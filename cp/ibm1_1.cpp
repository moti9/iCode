#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <algorithm>
#include <numeric>

using namespace std;

vector<string> parseUrlParameters(const string &url)
{
    vector<string> parameters;
    smatch match;
    if (regex_search(url, match, regex("\\?(.*)$")))
    {
        string paramString = match[1];
        istringstream iss(paramString);
        string parameter;
        while (getline(iss, parameter, '&'))
        {
            parameters.emplace_back(parameter);
        }
    }
    return parameters;
}

string validateRequest(const vector<string> &validAuthTokens, const vector<string> &request)
{
    const auto &requestType = request[0];
    const auto &url = request[1];

    vector<string> urlParameters = parseUrlParameters(url);

    auto tokenIt = find_if(urlParameters.begin(), urlParameters.end(),
                           [](const string &param)
                           { return param.find("token=") == 0; });

    if (tokenIt == urlParameters.end())
    {
        return "INVALID";
    }

    size_t tokenPos = tokenIt->find('=');
    string authToken = tokenIt->substr(tokenPos + 1);

    auto authTokenIt = find(validAuthTokens.begin(), validAuthTokens.end(), authToken);
    if (authTokenIt == validAuthTokens.end())
    {
        return "INVALID";
    }

    if (requestType == "POST")
    {
        auto csrfTokenIt = find_if(urlParameters.begin(), urlParameters.end(),
                                   [](const string &param)
                                   { return param.find("csrf=") == 0; });

        if (csrfTokenIt == urlParameters.end() || csrfTokenIt->substr(5).size() < 8 || !regex_match(csrfTokenIt->substr(5), regex("^[a-zA-Z0-9]+$")))
        {
            return "INVALID";
        }
    }

    string result = "VALID,";
    for (const auto &param : urlParameters)
    {
        size_t equalPos = param.find('=');
        if (equalPos != string::npos && param.substr(0, 4) == "name")
        {
            result += "name," + param.substr(equalPos + 1);
        }
    }

    return result;
}

vector<string> getResponses(const vector<string> &validAuthTokens, const vector<vector<string>> &requests)
{
    vector<string> results;

    for (const auto &request : requests)
    {
        string result = validateRequest(validAuthTokens, request);
        results.emplace_back(result);
    }

    return results;
}

int main()
{
    // Example usage:
    vector<string> validAuthTokens = {"ah37j2ha483u", "safh34ywb0p5", "ba34wyi8t902"};
    vector<vector<string>> requests = {
        {"GET", "https://example.com/?token=347sd6yk8iu2&name=alex"},
        {"GET", "https://example.com/?token=safh34ywb0p5&name=sam"},
        {"POST", "https://example.com/?token=safh34ywb0p5&name=alex"},
        {"POST", "https://example.com/?token=safh34ywb0p5&csrf=ak2sh32dy&name=chris"}};

    vector<string> results = getResponses(validAuthTokens, requests);

    for (const auto &result : results)
    {
        cout << result << endl;
    }

    return 0;
}
