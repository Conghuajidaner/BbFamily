// 朴素的排序，注意下可能会有重复数字就好了
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;    
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int ans = 1, len = nums.size();

        for (int i = 1; i < len; ++ i)
        {
            int j = i;
            while (j < len && nums[j] - nums[j - 1] == 1) j ++;
            ans = max(ans, j - i + 1);
            i = j;
        }
        return ans;
    }
};

--------------------------------------------------------------------
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>buf;
        for (auto &v: nums)
            buf.insert(v);

        int ans = 0;

        for (auto &v: buf)
        {
            if (buf.count(v - 1)) continue;
            int tmp = v + 1;
            while (buf.count(tmp)) tmp ++;
            ans = max(ans, tmp - v);
        }
        return ans;
    }
};
