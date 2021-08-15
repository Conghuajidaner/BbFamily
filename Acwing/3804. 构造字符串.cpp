// this solution is Accept
// train of thought: When n>=k, strAns = string(strans.begin (), strans.begin () + k), the strategy is to start at the end and find the first letter that exists ih thr charSet
//                   that can be replaced

#include <bits/stdc++.h>
using namespace std;

set<char> cSet;
void alterString(string& ans, string& source)
{
    for (int i = int(ans.length()) - 1; i >= 0; -- i)
        for (auto &c: cSet)
            if (c >  source[i])
            {
                ans[i] = c;
                for (int j = i + 1; j < int(ans.length()); ++ j) ans[j] = *(cSet.begin());
                return;
            }
}

int main()
{
    int numOfCase; cin >> numOfCase;
    while (numOfCase --)
    {
        int n, k; cin >> n >> k;
        string source; cin >> source;
        cSet.clear();
        string ans = "";
        for (auto &e: source) cSet.insert(e);
        if (n >= k) {
            ans = string(source.begin(), source.begin() + k);
            alterString(ans, source);
        } else if (n < k) {
            ans = source;
            for (int i = 0; i < k - n; ++ i) ans += *(cSet.begin());
        }
        cout << ans << endl;
    }
    return 0;
}
