// this solution accept
// Train of thought: There are seven conditions for the three kinds of fruit.
//                   Binary iterates over all cases, recoding the maximum result.

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int s[7][3] = {
    {0, 0, 1},
    {0, 1, 0},
    {0, 1, 1},
    {1, 0, 0},
    {1, 0, 1},
    {1, 1, 0},
    {1, 1, 1}
};

int main()
{
    int m; cin >> m;
    
    while (m -- )
    {
        int a, b, o; cin >> a >> b >> o;
        int ans = 0;
        for (int i = 0; i < 1<<7; ++ i)
        {
            int sa, sb, so, cur;
            sa = sb = so = cur = 0;
            for (int j = 0; j < 7; j ++)
            {
                if (i >> j & 1)
                {
                    sa += s[j][0];
                    sb += s[j][1];
                    so += s[j][2];
                    cur ++;
                }
            }
            if (sa <= a && sb <= b && so <= o) ans = max(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}
