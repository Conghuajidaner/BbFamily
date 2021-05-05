class Solution {
public:
    vector<int> searchRange(vector<int>& nums , int k) {
        if (nums.empty()) return vector<int>{-1, -1};
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (k > nums[mid]) l = mid + 1;
            else r = mid;
        }
        
        if (nums[l] != k) return vector<int>{-1, -1};
        
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (k >= nums[mid]) left = mid;
            else right = mid - 1;
        }
        
        return vector<int>{l, right};
    }
};
