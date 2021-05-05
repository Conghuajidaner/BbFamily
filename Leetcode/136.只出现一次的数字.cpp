class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tmp = 0;
        for (auto v: nums)
            tmp ^= v;
        return tmp;
    }
};
