/*
Question 5: Majority Element
The majority element in an array is defined as the element that
appears more than ⌊n/2⌋ times, where n is the length of the array.
In other words, it is the element that occurs most frequently and
makes up more than half of the array.

Given an array of integers, the task is to find the majority element
 and return it. If there is no majority element, If there is no majority element, the algorithm should indicate that.

Examples:

Example 1:
Input: [3, 3, 4, 2, 4, 4, 2, 4, 4]
Output: 4
Explanation:
In the given array, the number 4 appears 5 times, which is more
than half of the array size (9/2 = 4.5). Therefore, 4 is the majority element.

Example 2:
Input: [1, 2, 3, 4, 4, 4, 4]
Output: 4
Explanation:
In this case, the number 4 appears 4 times, which is more than half of the array size (7/2 = 3.5). Thus, 4 is the majority element.

Example 3:
Input: [1, 2, 3, 4, 5]
Output: -1
Explanation:
There is no majority element in this array since no number appears more than half of the array size (5/2 = 2.5).

Example 4:
Input: [2, 2, 2, 3, 3, 4, 4, 4, 4]
Output: -1
Explanation:

*/

#include <bits/stdc++.h>

int majorityElement(std::vector &nums)
{
    int count = 0;
    int candidate = 0;

    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
            count = 1;
        }
        else if (num == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return candidate;
}

int validateMajorityElement(std::vector &nums, int candidate)
{
    int count = 0;
    for (int num : nums)
    {
        if (num == candidate)
        {
            count++;
        }
    }

    if (count > nums.size() / 2)
    {
        return candidate;
    }
    else
    {
        return -1; // No majority element found
    }
}

int findMajorityElement(std::vector &nums)
{
    int candidate = majorityElement(nums);
    return validateMajorityElement(nums, candidate);
}

int main()
{
    std::vector nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int result = findMajorityElement(nums);

    if (result != -1)
    {
        std::cout << "Majority Element: " << result << std::endl;
    }
    else
    {
        std::cout << "No majority element found." << std::endl;
    }

    return 0;
}
