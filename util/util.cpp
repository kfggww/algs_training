#include "util.h"
#include <memory>
#include <cstring>

namespace algst
{
    namespace util
    {
        void swap(int *a, int *b)
        {
            int c = *a;
            *a = *b;
            *b = c;
        }

        void merge(int *nums, int start, int mid, int end)
        {
            int i = 0;
            int j = mid + 1 - start;

            int *nums_copy = (int *)malloc(sizeof(int) * (end - start + 1));
            memcpy(nums_copy, nums + start, sizeof(int) * (end - start + 1));

            for (int index = start; index <= end; ++index)
            {
                if (i <= mid - start && j <= end - start)
                {
                    nums[index] = (nums_copy[i] <= nums_copy[j]) ? nums_copy[i++] : nums_copy[j++];
                }
                else if (i > mid - start)
                {
                    nums[index] = nums_copy[j++];
                }
                else
                {
                    nums[index] = nums_copy[i++];
                }
            }
        }
    }
}