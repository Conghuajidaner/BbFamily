// Question: Find the number that appears once int the array.

// Solution: Examine the first to the penultimate element in an array and print its index if it is not equal to the first and not equal to the next

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
int arr[N];

int main()
{
    int m; cin >> m;
    
    while (m --)
    {
        int n; cin >> n;
        bool flag = false;
        for (int i = 0; i < n; ++ i) scanf("%d", &arr[i]);

        for (int i = 1; i < n - 1; ++ i)
        {
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
            {
                cout << i + 1;
                flag = true;
                break;
            }
        }
        if (!flag) {
            if (arr[0] != arr[1])
                cout << 1;
            else
                cout << n;
        }
        if (m) cout << endl;
    }
    return 0;
}
