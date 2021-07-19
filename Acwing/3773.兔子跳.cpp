// this solution is Accept.
// tarin of thought: record the max number between step length, if largest number less than x, the result is an upward rounding of max_num and x.
//                   Otherwise, the answer is 2。
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int countOfCase; cin >> countOfCase;
    
    while (countOfCase --)
    {
        int n, x; cin >> n >> x;
        int maxNumOfStepLength = INT_MIN;
        
        bool flag = true;
        for (int idx = 0; idx < n; ++ idx)
        {
            int tmp; cin >> tmp;
            if (tmp == x) flag = false;
            maxNumOfStepLength = max(maxNumOfStepLength, tmp);
        }
        
        if (flag == false) cout << 1 << endl;
        else {
            if (maxNumOfStepLength < x) {
                cout << (x + maxNumOfStepLength - 1) / maxNumOfStepLength << endl;
            } else {
                cout << 2 << endl;
            }
        }
    }
    return 0;
}
