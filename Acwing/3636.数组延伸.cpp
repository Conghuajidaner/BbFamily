// this solution is accept
// Train of thought: Examine each element, find the minimum number of times an array is divisible
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m; cin >> m;
    
    while (m -- )
    {
        int n, k; cin >> n >> k;
        vector<int>buf(n);
        for (int i = 0; i < n; ++ i) scanf("%d", &buf[i]);   
        long long sum = 0, psum = 0;
        int cnt = INT_MAX;
        for (int i = 0; i < n; ++ i)
        {
            sum += buf[i];
            int curCnt = 0;
            
            for (int j = buf[i]; j % k == 0; j /= k) curCnt ++;
            if (cnt > curCnt)
            {
                cnt = curCnt;
                psum = sum - buf[i];
            }
        }
        cout << psum + (cnt + 1) * sum << endl;
    }   
    return 0;
}

// this solution time out
// Train of thought: Examine each element and, if it is available, put it in the array.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m; cin >> m;
    
    while (m -- )
    {
        int n; cin >> n;
        int k; cin >> k;
        vector<int>buf(n);
        for (int i = 0; i < n; ++ i) scanf("%d", &buf[i]);
        for (int i = 0; i < buf.size(); ++ i)
            if (buf[i]%k == 0)
            {
                for (int j = 0; j < k; ++ j) buf.push_back(buf[i]/k);
            } else break;
      
        int sum = 0;
        for (auto &e: buf) sum += e;
        cout << sum << endl;
    }
    return 0;
}

// this solution time out
// Train of though: Examine each element of buf and, if it is available, put it to add array.
//                  Eaxmine each element of add and, if it is available, put it to add array. 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m; cin >> m;
    while (m -- )
    {
        int n, k; cin >> n >> k;
        vector<int>buf(n);
        vector<vector<int>>add;
        for (int i = 0; i < n; ++ i) scanf("%d", &buf[i]);
        long long ans = 0;
        bool flag = true;
        for (int i = 0; i < n; ++ i)
        {
            ans += buf[i];
            if (flag && buf[i]%k == 0)
            {
                add.push_back({buf[i]/k, k});
            } else flag = false;
        }
        for (int i = 0; i < add.size(); ++ i)
        {
            ans += add[i][0] * add[i][1];
            if (flag && add[i][0]%k == 0)
            {
                add.push_back({add[i][0]/k, k*add[i][1]});
            } else flag = false;
        }
        cout << ans << endl;
    }
    return 0;
}

// this solution accept
