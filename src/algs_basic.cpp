#include "algs_basic.h"
#include "util.h"

namespace algst
{
    static void merge_sort_internal(int *nums, int *nums_copy, int start, int end);

    /**
     * @brief quick sort algorithm implementation.
     *
     * @param nums
     * @param start
     * @param end
     */
    void qsort(int *nums, int start, int end)
    {
        if (start >= end)
            return;

        int flag = nums[start];
        int i = start + 1;
        int j = end;

        while (i < j)
        {
            while (i <= j && nums[i] <= flag)
                i++;
            while (i <= j && nums[j] >= flag)
                j--;
            if (i < j)
                util::swap(&nums[i], &nums[j]);
        }

        util::swap(&nums[start], &nums[j]);
        qsort(nums, start, j - 1);
        qsort(nums, j + 1, end);
    }

    /**
     * @brief merge sort interface.
     *
     * @param nums
     * @param start
     * @param end
     */
    void msort(int *nums, int start, int end)
    {
        if (start >= end)
            return;
        int mid = (start + end) / 2;
        msort(nums, start, mid);
        msort(nums, mid + 1, end);
        util::merge(nums, start, mid, end);
    }
}