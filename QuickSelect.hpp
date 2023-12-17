#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <algorithm>

std::vector<int>::iterator medianOfThree(std::vector<int>::iterator& low, std::vector<int>::iterator& high)
{
    auto middle = low + distance(low, high) / 2;

    if ((*low < *middle && *middle < *high) || (*high < *middle && *middle < *low))
    {
        std::swap(*middle, *high);
    }
    else if ((*middle < *low && *low < *high) || (*high < *low && *low < *middle))
    {
        std::swap(*low, *high);
    }

    return high;
}


std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{
    auto pivot = medianOfThree(low, high);
    int pivotVal = *pivot;

    iter_swap(pivot, high); 

    auto lo = low;
    auto hi = high;

    while (true)
    {
        while (lo < hi && *lo < pivotVal)
        {
            lo++;
        }
        while (hi > lo && *hi >= pivotVal)
        {
            hi--;
        }

        if (lo >= hi)
        {
            break;
        }

        std::swap(*lo, *hi);
    }

    std::swap(*lo, *high); 
    return lo; 
}

int quickSelectDriver(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, int x)
{
    if (high - low < 1e1)
    {
        std::sort(low, high + 1); 
        return *(low + x); 
    }

    auto parting = hoarePartition(nums, low, high); 
    int distance = std::distance(low, parting);

    if (distance == x)
    {
        return *parting; 
    }
    else if (distance > x)
    {
        return quickSelectDriver(nums, low, parting - 1, x); 
    }
    else
    {
        return quickSelectDriver(nums, parting + 1, high, x - distance - 1);
    }
}


int quickSelect(std::vector<int>& nums, int& duration)
{
    auto START = std::chrono::high_resolution_clock::now(); 

    int mid = (nums.size() - 1) / 2;

    quickSelectDriver(nums, nums.begin(), nums.end() - 1, mid); 

    auto END = std::chrono::high_resolution_clock::now(); 
    auto time_lapse = std::chrono::duration_cast<std::chrono::milliseconds>(END - START);
    duration = static_cast<int>(time_lapse.count()); 

    return nums[mid]; 
}