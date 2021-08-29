// this solution is Accept
// train of thought: 博弈论
#include<iostream>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    
    if (1l * n * m % 2) cout << "akai";
    else cout << "yukari";
    return 0;
}
