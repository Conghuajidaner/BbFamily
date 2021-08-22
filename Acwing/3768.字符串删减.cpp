#include<bits/stdc++.h>

using namespace std;

int main()
{
    int strLength; cin >> strLength;
    string str; cin >> str;
    int ans = 0;
    for (int idx = 0; idx < strLength;)
    {
        if (str[idx] != 'x') { 
            idx ++; continue;
        }
        int next = idx;
        while (next < strLength && str[next] == 'x') next ++;
        // ans += next - idx - 2; this step is error beacuse it should be unsigned int.
        ans += max(0, next - idx - 2);
        idx = next;
    }
    
    cout << ans << endl;
    return 0;
}
