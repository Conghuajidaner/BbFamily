// 做的比较丑陋，一开始想的是 ans = ((sum += (buf[i] - buf[n/2])/((n + 1) / 2) + buf[n/2]);  但是后面的如果特别大就会假
// 第二想法是差分，但是想了想好像不用太麻烦，但是漏了一个可能会相等的情况，被卡掉，后面特判一下
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    
    vector<int>buf(n);
    for (int i = 0; i < n; ++ i) cin >> buf[i];
    sort(buf.begin(), buf.end());
    
    int tmp = buf[n/2];
    for (int i = n/2 + 1; i < n && k > 0; ++ i)
    {
        while (buf[i] > tmp)
        {
            if (k >= i - n/2)
            {
                tmp ++;
                k -= (i - n/2);
            } else {
                cout << tmp;
                return 0;
            }
        }
    }
    if (k != 0) {
        tmp += k / ((n + 1) / 2);
    }
    cout << tmp;
    return 0;
}
