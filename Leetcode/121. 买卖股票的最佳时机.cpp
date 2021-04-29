class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int tmp = INT_MAX, ans = 0, len = prices.size();
    
        for (int i = 0; i < len; ++ i)
        {
            tmp = min(tmp, prices[i]);
            ans = max(ans, prices[i] - tmp);
        }
        return ans;
    }
};

-----------------------------------------------------------------------

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //可以转化成区间最大和的问题
        int n = prices.size();
        vector<int>buff; buff.clear();
        int ans = 0;

        for (int i = 1; i < n; ++i) {
            buff.push_back(prices[i] - prices[i - 1]);
        }
        int cur = 0;
        for (int i = 0; i < buff.size(); ++i) {
            if (cur >= 0 && buff[i] > 0) {
                cur += buff[i];
                ans = max (ans, cur);
            } else if (cur < 0 && buff[i] <= 0) {
                continue;
            } else if (cur >= 0 && cur + buff[i] < 0) {
                cur = 0;
            } else {
                cur += buff[i];
            }
        }
        return ans;
    }
};
