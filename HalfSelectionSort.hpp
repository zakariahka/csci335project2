#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

int halfSelectionSort(std::vector<int> &nums, int &duration)
{
    auto START = std::chrono::high_resolution_clock::now();

    if (nums.size() > 50000)
    {
        std::cout << "Input is larger than 50,000. Insert a smaller input." << std::endl;
        return -1;
    }

    auto halfPoint = nums.begin() + nums.size() / 2;

    if (nums.size() % 2 == 0)
    {
        halfPoint = (nums.begin() + nums.size() / 2) - 1;
    }

    for (auto index = nums.begin(); index <= halfPoint; ++index)
    {
        auto minimum = min_element(index, nums.end());
        iter_swap(index, minimum);
    }

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