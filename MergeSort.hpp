#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <algorithm>

int mergeSort(std::vector<int> &nums)
{
    if (nums.size() <= 1)
    {
        return *nums.begin();
    }

    std::vector<int> left_side(nums.begin(), nums.begin() + nums.size() / 2);
    std::vector<int> right_side(nums.begin() + nums.size() / 2, nums.end());

    mergeSort(left_side);
    mergeSort(right_side);

    merge(left_side.begin(), left_side.end(), right_side.begin(), right_side.end(), nums.begin());
}

int mergeSort(std::vector<int> &nums, int &duration)
{
    auto START = std::chrono::high_resolution_clock::now();

    mergeSort(nums);

    auto END = std::chrono::high_resolution_clock::now();
    auto time_lapse = std::chrono::duration_cast<std::chrono::milliseconds>(END - START);
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