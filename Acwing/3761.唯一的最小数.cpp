// This solution is Accept.
// Train of thought: Use the map to record the number of occurences and the index of the fitst occurences.

// Better idea: the number range is relatively samll, can be directly array record.
#include<bits/stdc++.h>
using namespace std;

map<int, pair<int, int>>stateNumList;

int main()
{
    int numOfCaseAmount; cin >> numOfCaseAmount;
    while (numOfCaseAmount --)
    {
        stateNumList.clear();
        int num; cin >> num;
        
        for (int i = 0; i < num; ++ i)
        {
            int tmp; cin >> tmp;
            
            if (stateNumList.count(tmp) == 0)
            {
                stateNumList[tmp] = make_pair(i + 1, 1);
            } else {
                stateNumList[tmp].second ++;
            } 
        }
        
        bool flag = true;
        for (auto &[key, value]: stateNumList)
        {
            if (value.second == 1)
            {
                cout << value.first << endl;
                flag = false;
                break;
            }
        }
        if (flag) cout << -1 << endl;
    }
    return 0;
}
