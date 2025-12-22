#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> groupConsecutive(const std::vector<int>& arr) {
    std::vector<std::string> result;
    if (arr.empty()) return result;

    int start = arr[0];
    int count = 1;

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] == arr[i - 1] + 1) {
            ++count;
        } else {
            result.push_back("'" + std::to_string(start - 1) + "+" + std::to_string(count) + "'");
            start = arr[i];
            count = 1;
        }
    }

    result.push_back("'" + std::to_string(start - 1) + "+" + std::to_string(count) + "'");

    return result;
}

int main() {
    std::vector<int> arr1 = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 22, 23, 24, 25, 26, 27, 28, 29, 40};
    std::vector<int> arr2 = {2, 3, 4, 7, 8};

    auto res1 = groupConsecutive(arr1);
    auto res2 = groupConsecutive(arr2);

    for (const auto& s : res1) std::cout << s << " ";
    std::cout << std::endl;
    for (const auto& s : res2) std::cout << s << " ";
    std::cout << std::endl;

    return 0;
}
