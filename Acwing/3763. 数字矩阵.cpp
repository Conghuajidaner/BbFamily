// Train of thought: MinNum should be the lowest absolute value number
// this solution is Accept
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int numOfCase;
    cin >> numOfCase;

    while (numOfCase--)
    {
        int count = 0, sum = 0, minNum = 999999;
        int n, m; cin >> n >> m;
        auto buf = vector<vector<int>>(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                cin >> buf[i][j];
                if (buf[i][j] <= 0) count ++;
                sum += abs(buf[i][j]);
                minNum = min(minNum, abs(buf[i][j]));
            }
        if (count % 2 == 1) {
            cout << sum - 2*minNum << endl;
        } else {
            cout << sum << endl;
        }
    }

    return 0;
}
