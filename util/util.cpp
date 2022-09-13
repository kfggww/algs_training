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
            int i = start;
            int j = mid + 1;
            int pos = 0;
            int *nums_merge = (int *)malloc(sizeof(int) * (end - start + 1));

            while (i <= mid || j <= end)
            {
                if (i > mid)
                {
                    nums_merge[pos++] = nums[j++];
                }
                else if (j > end)
                {
                    nums_merge[pos++] = nums[i++];
                }
                else
                {
                    nums_merge[pos++] = (nums[i] <= nums[j]) ? nums[i++] : nums[j++];
                }
            }

            memcpy(nums + start, nums_merge, sizeof(int) * (end - start + 1));
            free(nums_merge);
        }
    }
}