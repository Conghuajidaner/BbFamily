#include<bits/stdc++.h>

using namespace std;
const int N = 1e6;


unordered_map<int, int>sTable;

int main()
{
    int left, right;
    left = N/2;
    right = left + 1;
    int w, tmp; cin >> w;
    while (w --)
    {
        char op; cin >> op;

        switch(op)
        {
            case '?':{
                cin >> tmp;
                int idx = sTable[tmp];
                cout << min(abs(idx - left), abs(idx - right)) - 1 << endl;
            };break;

            case 'L':{
                cin >> tmp;
                sTable[tmp] = left --;
            };break;

            case 'R':{
                cin >> tmp;
                sTable[tmp] = right ++;
            };break;
        }
    }
    return 0;
}
