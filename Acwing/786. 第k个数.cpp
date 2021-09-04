// this solution is Accept
// train of thought: quick sort
#include<iostream>
#include<vector>

using namespace std;

int quickQuery(int l, int r, int k, vector<int>&buf)
{
    if (l == r) return buf[l];
    int i = l - 1, j = r + 1, guard = buf[(l + r) >> 1];
    
    while (i < j)
    {
        do {++ i;} while (buf[i] < guard);
        do {-- j;} while (buf[j] > guard);
        if (i < j) swap(buf[i], buf[j]);
    }
    
    int len = j - l + 1;
    if (len >= k) return quickQuery(l, j, k, buf);
    else return quickQuery(j + 1, r, k - len, buf);
}

int main()
{
    int n, k; cin >> n >> k;
    vector<int> buf(n);
    for (int i = 0; i < n; ++ i) cin >> buf[i];

    cout << quickQuery(0, n - 1, k, buf);
    
    return 0;
}
