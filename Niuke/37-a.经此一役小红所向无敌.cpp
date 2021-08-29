// https://ac.nowcoder.com/acm/contest/11214/A
// this solution is Accept
// train of thought: Count the number of rounds to finish.
#include <iostream>

using namespace std;

int main()
{
    int a, h, b, k;
    cin >> a >> h >> b >> k;
    int m = (k + a - 1) / a, n = (h + b - 1) / b;
    if (m == n) cout << m * (a + b);
    else if(m > n) {
        cout << 1l * n * (a + b) + b * 10;
    } else {
        cout << 1l * m * (a + b) + a * 10;
    }
    return 0;
}
