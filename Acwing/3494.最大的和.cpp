// this solution is accept
// train of thought: Prefix Sum，sliding window
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

long long arr[N], flag[N];

int main()
{
    int n, k; cin >> n >> k;
    long long ans = 0;

    for (int i = 0; i < n; ++ i) cin >> arr[i];
    for (int i = 0; i < n; ++ i) cin >> flag[i];

    for (int i = 0; i < n; ++ i)
    {
        if (flag[i] == 1)
        {
            ans += arr[i];
            arr[i] = 0;
        }
    }

    long long maxWinNum = 0;
    for (int i = 0; i < k; ++ i) maxWinNum += arr[i];
    long long curWinNum = maxWinNum;
    for (int i = k; i < n; ++ i)
    {
        curWinNum = curWinNum - arr[i - k] + arr[i];
        maxWinNum = max(maxWinNum, curWinNum);
    }
    cout << ans + maxWinNum;
    return 0;
}
