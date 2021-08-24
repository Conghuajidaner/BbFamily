#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int n; cin >> n;
    unordered_map<string, int> buf;

    for (int i = 0; i < n; ++ i) {
        string tmp; cin >> tmp;
        buf[tmp] ++;
    }

    int ans = 0;
    for (auto &kv: buf)
    {
        ans = max(ans, kv.second);
    }
    cout << ans;
    return 0;
}
