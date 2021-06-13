// this solution accept
// 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m; cin >> m;
    while (m--)
    {
        string str; cin >> str;
        int ans = INT_MAX;
        int cnt[3] = {0};
        for (int i = 0, j = 0; i < str.length(); ++ i)
        {
            cnt[str[i] - '1'] ++;
            while (cnt[str[j] - '1'] > 1) cnt[str[j++] - '1']--;
            if (cnt[0] && cnt[1] && cnt[2])
                ans = min(ans, i - j + 1);
        }
        if (ans == INT_MAX) cout << 0 << endl;
        else cout << ans << endl;
    }
    return 0;
}


// this solution is accept
// Train of rhought:Map is less efficient
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
            // This step doesn't have to satisfy this condition. if it does, update ans.
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
