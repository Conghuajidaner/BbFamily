class Solution {
public:
    string removeDuplicates(string S) {
        stack<char>buf;

        for (auto c: S)
        {
            if (!buf.empty() && c == buf.top())
                buf.pop();
            else buf.push(c);
        }

        string ans = "";
        
        while (!buf.empty())
        {
            ans += buf.top();
            buf.pop();
        }
        return string(ans.rbegin(), ans.rend());
    }
};

================================================
// 小丑竟是我自己
class Solution {
public:
    string removeDuplicates(string S) {
        string ans = "";

        for (auto &c: S)
        {
            if (ans != "" && c == ans.back())
                ans.pop_back();
            else
                ans.push_back(c);
        }
        return ans;
    }
};
