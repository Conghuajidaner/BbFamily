// this solution is accept
// Train of thought: Special judgment is less than 2, and then round up the remaining floors.
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m; cin >> m;
    
    while (m -- )
    {
        int a, b; cin >> a >> b;
        if (a <= 2) cout << 1 << endl;
        else {
            cout << (a - 2 + b - 1)/b + 1 << endl;
        }
    }
    return 0;
}
