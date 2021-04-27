/*
*   只会对应一个答案，所以这个算法才可以解。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>buf;
        for (int i = 0; i < nums.size(); ++ i)
        {
            if (buf.find(target - nums[i]) != buf.end()) return {buf[target - nums[i]], i};
            buf[nums[i]] = i;
        }
        return {};
    }
};