class Solution {
public:
    string replaceDigits(string s) {
        int len = s.length();
        vector<int>buf;
        for (int i = 1; i < len; i += 2)
        {
            buf.push_back(s[i] - '0');
        }
        buf = vector<int>(buf.rbegin(), buf.rend());
        for (int i = 1; i < len; i += 2)
        {
            s[i] = s[i - 1] + buf.back();
            buf.pop_back();
        }
        return s;
    }
};
