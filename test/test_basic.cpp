#include <gtest/gtest.h>
#include <cstdio>
#include "algs_basic.h"

TEST(TestBasic, TestQuickSort)
{
    int nums[] = {12, 123, 2, 2, 3, 4};
    algst::qsort(nums, 0, sizeof(nums) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(nums) / sizeof(int); ++i)
    {
        printf("%d\n", nums[i]);
    }
}

TEST(TestBasic, TestMergeSort)
{
    int nums[] = {12, 1, 34, 23, 12, 45};
    algst::msort(nums, 0, sizeof(nums) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(nums) / sizeof(int); ++i)
    {
        printf("%d\n", nums[i]);
    }
}