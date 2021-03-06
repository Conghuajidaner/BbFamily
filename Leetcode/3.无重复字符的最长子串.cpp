
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, len = s.length();
        map<char, int>buf;

        for (int i = 0, j = 0; i < len && j < len; ++ j)
        {
            buf[s[j]] ++;
            while (buf[s[j]] > 1) {
                buf[s[i ++]] --;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};