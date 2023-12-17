#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

int inPlaceMergeDriver(std::vector<int> &nums, int start, int end)
{
    if (end - start <= 1)
    {
        return nums[start];
    }

    int mid = start + (end - start) / 2;

    inPlaceMergeDriver(nums, start, mid);
    inPlaceMergeDriver(nums, mid, end);

    std::inplace_merge(nums.begin() + start, nums.begin() + mid, nums.begin() + end);
    return nums[start];
}

int inPlaceMergeSort(std::vector<int> &nums, int &duration)
{
    auto START = std::chrono::high_resolution_clock::now();

    inPlaceMergeDriver(nums, 0, nums.size());

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
