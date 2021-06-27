// This solution is accept
// Train of thought: Greedy algorithm, Calculate the sum of the distances between the numbers 1
#include<bits/stdc++.h>

using namespace std;

const int N = 55;

int main()
{
    int m; cin >> m;
    
    while (m -- )
    {
        int num, ans = 0; cin >> num;
        vector<int>buf;
        for(int i = 0; i < num; ++ i)
        {
            int tmp; cin >> tmp;
            if (tmp == 1)
                buf.push_back(i);
        }
        for(int i = 1; i < (int)buf.size(); ++ i)
        {
            ans += buf[i] - buf[i - 1] - 1;
        }
        cout << ans << endl;
    }
    return 0;
}
