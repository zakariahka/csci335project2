#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

int standardSort(std::vector<int> &nums, int &duration)
{
    auto START = std::chrono::high_resolution_clock::now();

    sort(nums.begin(), nums.end());

    auto END = std::chrono::high_resolution_clock::now();
    auto time_lapse = std::chrono::duration_cast<std::chrono::microseconds>(END - START);
    duration = static_cast<int>(time_lapse.count());

    if (nums.size() % 2 == 0)
    {
        return *(nums.begin() + nums.size() / 2 - 1);
    }
    else
    {
        return *(nums.begin() + nums.size() / 2);
    }
}