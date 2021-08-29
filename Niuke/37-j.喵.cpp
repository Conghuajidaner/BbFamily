// https://ac.nowcoder.com/acm/contest/11214/J
// this solution is Accept
// train of thought: Delete the last three characters of the string
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    cout << string(str.begin(), str.end() - 3) << endl;
    return 0;
}
