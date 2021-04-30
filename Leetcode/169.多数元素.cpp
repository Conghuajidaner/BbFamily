// Boyer-Moore投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate) ++count;
            else count --;
            
            if (count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};
=========================================================

// 排序
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
========================================================
// 哈希
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int>count;
      
        for (auto &v: nums) count[v] ++;
        for (auto &m: count)
        if (m.second > len/2) return m.first;
       // 数据正常是运行不到这里的 
       return -1;
    }
};
=======================================================
// 官方还有一个随机数法：大致就是随便挑一个数字，是众数就返回，不是就重新选
  
=======================================================
// 分支法, 递归的计算区间的众数，记录区间众数以及出现次数
