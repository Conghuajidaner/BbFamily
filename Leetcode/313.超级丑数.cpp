// ans是必须的，笨一点的动态规划
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1) return 1;
        
        vector<double>ans(n + 1, INT_MAX);
        vector<double>buf(primes.size(), 0);
        ans[0] = 1;
        for (int i = 1; i <= n; ++ i)
        {
            for (int j = 0; j < primes.size(); ++ j)
            {
                ans[i] = min(ans[buf[j]] * primes[j], ans[i]);
            }
            for (int j = 0; j < primes.size(); ++ j)
            {
                if (ans[i] == ans[buf[j]] * primes[j])
                    buf[j] ++;
            }
        }
        return ans[n - 1];
    }
};

=============================
//标程
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1) return 1;
        int k = primes.size();
        vector<int> dp(n, 1);
        vector<int> p(k, 0);
        vector<int> num(k, 0);
        int count = 1;
        for (int i = 0; i < k; i++) num[i] = primes[i] * dp[p[i]];
        while (count < n) {
            int m = *min_element(num.begin(), num.end());
            dp[count] = m;
            for (int i = 0; i < k; i++) {
                if (num[i] == m) {
                    p[i]++;
                    num[i] = primes[i] * dp[p[i]];
                }
            }
            count++;
        }
        return dp[n - 1];
    }
};
