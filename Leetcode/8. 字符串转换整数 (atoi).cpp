class Solution {
   public:
    int myAtoi(string str) {
        double ans = 0;
        int len = str.length();
        int idx = 0;
        int flag = 0;
        while (idx < len && str[idx] == ' ') idx++;
        if (str[idx] == '+' || str[idx] == '-')
            if (str[idx ++] == '-') flag = 1;

        string buff = "";
        while (idx < len && str[idx] >= '0' && str[idx] <= '9')
            buff += str[idx ++];
        for (int i = 0, j = buff.length() - 1; i < buff.length(); ++i, -- j) {
            ans += (buff[i] - '0') * pow(10, j);
            if (flag && ans < INT_MIN) return INT_MIN;
            if (!flag && ans > INT_MAX) return INT_MAX;
        }

        if (flag) ans *= -1;
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        return ans;
    }
};