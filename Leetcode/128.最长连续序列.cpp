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
// 大不对劲
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;           
    }
};
