#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m; cin >> m;
    while (m--)
    {
        string str; cin >> str;
        int left = 0, right = 0, ans = INT_MAX;
        map<char, int> cnt;
        for (; right < str.length(); )
        {
            while (right < str.length() && !(cnt['1'] > 0 && cnt['2'] > 0 && cnt['3'] > 0))
            {
                cnt[str[right]] ++;
                right++;
            }
   
            while (left < right && cnt['1'] > 0 && cnt['2'] > 0 && cnt['3'] > 0)
            {
                ans = min(right - left, ans);
                cnt[str[left]] --;
                left++;
            }
        }
        if (ans == INT_MAX) cout << 0 << endl;
        else cout << ans << endl;
    }
    return 0;
}
