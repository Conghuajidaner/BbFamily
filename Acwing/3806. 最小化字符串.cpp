#include <iostream>

using namespace std;

int main()
{
    int numOfCase;
    cin >> numOfCase;

    while (numOfCase--)
    {
        int lenOfSourceStr; cin >> lenOfSourceStr;
        string sourceStr; cin >> sourceStr;
        bool flag = false;

        for (int i = 1; i < lenOfSourceStr; ++i)
        {
            auto &s = sourceStr;
            if (s[i] < s[i - 1]) {
                flag = true;
                cout << string(s.begin(), s.begin() + i - 1)  << string(s.begin() + i, s.end()) << endl;
                break;
            }
        }
        if (!flag) cout << string(sourceStr.begin(), sourceStr.begin() + lenOfSourceStr - 1) << endl;
    }
    return 0;
}