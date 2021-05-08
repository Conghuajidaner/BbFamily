// ans是必须的

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
