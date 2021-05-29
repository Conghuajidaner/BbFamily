#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; cin >> n;
    set<int>bufA, bufB;
    while (n --)
    {
        int tmp; cin >> tmp;
        bufA.insert(tmp);
    }
    cin >> m;
    while (m --)
    {
        int tmp; cin >> tmp;
        bufB.insert(tmp);
    }
    
    for (auto &efA: bufA)
    {
        for (auto &efB: bufB)
        {
            if (!bufA.count(efA + efB) && !bufB.count(efA + efB))
            {
                cout << efA << " " << efB;
                return 0;
            }
        }
    }
    return 0;
}
