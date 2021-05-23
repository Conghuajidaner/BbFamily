// 没啥特别的算法，就是注意下不要越界还有就是 j最后的的设置
class Solution {
public:
    bool checkZeroOnes(string s) {
        int sLen = s.length();
        int zeroLen = 0, oneLen = 0;

        for (int i = 0; i < sLen;)
        {
            int j = i;
            while (j < sLen && s[j] == s[i]) j ++;
            if (s[i] == '1')
                oneLen = max(j - i, oneLen);
            else
                zeroLen = max(j - i, zeroLen);
            i = j;
        }
        return oneLen > zeroLen;
    }
};
