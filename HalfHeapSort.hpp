#ifndef HALFHEAPSORT_HPP
#define HALFHEAPSORT_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

    inline int leftChild(int i){
        return 2 * i;
    }

    void percDown(std::vector<int>& heap, std::vector<int>::size_type hole){
        int child;
        int temp = heap[0];

        for (; leftChild(hole) < heap.size(); hole = child){
            child = leftChild(hole);

            if (child < heap.size() - 1 && heap[child] > heap[child + 1])
                ++child;

            if (temp > heap[child])
                heap[hole] = heap[child];
            else
                break;
        }

        heap[hole] = temp;
    }

    void buildHeap(std::vector<int>& heap){
        for(int i = (heap.size() - 1 / 2); i > 0; i--){
            heap[0] = heap[i];
            percDown(heap, i);
        }
    }

    int halfHeapSort(std::vector<int>& nums, int& duration){
        auto start = std::chrono::steady_clock::now();

        nums.push_back(nums[0]);
        buildHeap(nums);

        int center = ((nums.end() - nums.begin()) - 2) / 2;

        for(int i = 0; i < center; i++) {
            nums[0] = nums[nums.size() - 1];
            nums.pop_back();
            percDown(nums, 1);
        }

        auto end = std::chrono::steady_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        return nums[1];
    }

#endif