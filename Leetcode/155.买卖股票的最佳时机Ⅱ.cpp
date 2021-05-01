class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); ++ i)
        {
            int tmp = prices[i] - prices[i - 1];
            ans += max(0, tmp);
        }
        return ans;
    }
};
