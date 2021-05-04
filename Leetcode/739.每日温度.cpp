// 呆比的暴力200+ms
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int len = t.size();
        vector<queue<int>>buf(101);
        vector<int>ans(len, 0);
        for (int i = 0; i < len; ++ i)
            buf[t[i]].push(i);

        for (int i = 0; i < len; ++ i)
        {
            int tmp = INT_MAX;
            for (int j = t[i] + 1; j <= 100; ++ j)
            {
                while (!buf[j].empty() && buf[j].front() < i) buf[j].pop();
                if (!buf[j].empty()) tmp = min(tmp, buf[j].front() - i);
            }
            if (tmp == INT_MAX) ans[i] = 0;
            else ans[i] = tmp;
        }
        ans[len - 1] = 0;
        return ans;
    }
}; 

=======================================================================
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n), next(101, INT_MAX);
        for (int i = n - 1; i >= 0; --i) {
            int warmerIndex = INT_MAX;
            for (int t = T[i] + 1; t <= 100; ++t) {
                warmerIndex = min(warmerIndex, next[t]);
            }
            if (warmerIndex != INT_MAX) {
                ans[i] = warmerIndex - i;
            }
            next[T[i]] = i;
        }
        return ans;
    }
};

===================================================================
  
  class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && T[i] > T[s.top()]) {
                int previousIndex = s.top();
                ans[previousIndex] = i - previousIndex;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
===============================================================
// KMP解法
  class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        n=len(T)
        ans=[0]*n
        for i in range(n-2,-1,-1):
            now=i+1
            while T[now]<=T[i]:
                if ans[now]:
                    now+=ans[now]
                else:
                    break
            else:
                ans[i]=now-i
        return ans
