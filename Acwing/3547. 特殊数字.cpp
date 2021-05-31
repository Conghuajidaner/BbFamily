#include<bits/stdc++.h>

using namespace std;

bool isSNum(int num)
{
    int ans = 0;
    while (num)
    {
        ans += (num%10);
        num /= 10;
    }
    return ans%4 == 0;
}

int main()
{
    int n; cin >> n;

    for (int i = n; i <= 1000 ; ++ i)
    {
        if (isSNum(i))
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}
