// this solution is accept
// Train of thought: Calculate the Euclidean distance
#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;   
    for (int i = 0; i < 2*n + 1; ++ i)
    {
        for (int j = 0; j < 2*n + 1; ++ j)
        {
            int d = abs(i - n) + abs(j - n);
            if (d > n) cout << "  ";
            else cout << n - d << " ";
        }
        cout << endl;
    }
    return 0;
}

// this solution is accept
// Train of thought: Set the number in the middle and extend to the left and right.
#include <iostream>
using namespace std;

const int N = 30;
char edge[N][N];

int main()
{
    int n; cin >> n;
    
    for (int i = 0; i < 2*n + 1; ++ i)
        for (int j = 0; j < 2*n + 1; ++ j)
            edge[i][j] = ' ';

    for (int i = n, j = n; j < 2*n + 1; i --, j ++)
        edge[i][n] = edge[j][n] = '0' + i;
    
    for (int i = 0; i < 2*n + 1; ++ i)
        for (int count = edge[i][n] - '0', j = n, k = n; count >= 0; --count, -- j, ++ k)
            edge[i][j] = edge[i][k] = '0' + count;
    
    for (int i = 0; i < 2*n + 1; ++ i)
    {
        for (int j = 0; j < 2*n + 1; ++ j)
            cout << edge[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
