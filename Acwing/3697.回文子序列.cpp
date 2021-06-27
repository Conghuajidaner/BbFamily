// This solution is accept
// Train of thought: Check the element i and j, and if they are equal and the difference is greater than 1, print "YES",  otherwise print "NO"

#include<bits/stdc++.h>

using namespace std;
const int N = 5010;

int arrayNum[N];
int main()
{
    int m; cin >> m;
    while (m -- )
    {
        // memset(arrayNum, 0, sizeof arrayNum);
        // 这里不需要memset
        int num; cin >> num;
        for (int i = 0; i < num; ++ i) cin >> arrayNum[i];
        bool flag = true;
        
        for (int i = 0; i < num && flag; ++ i)
            for (int j = i + 2; j < num && flag; ++ j)
                if (arrayNum[i] == arrayNum[j])
                {
                    cout << "YES" << endl;
                    flag = false;
                }
      
        if (flag) cout << "NO" << endl;
    }
    return 0;
}
