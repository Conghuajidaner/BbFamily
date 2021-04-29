class Solution {
public:
    void quickSort(vector<int>&nums, int left, int right)
    {
        if (left >= right) return;
        int i = left - 1, j = right + 1, mid = nums[(left + right) >> 1];
        while (i < j)
        {
            do ++i; while (i < j && nums[i] > mid);
            do --j; while (j >= 0 && nums[j] < mid);
            if (i < j) swap(nums[i], nums[j]);
        }
        quickSort(nums, left, j);
        quickSort(nums, j + 1, right);
    }

    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size() - 1);
        return nums[k - 1];
    }
};
