#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N =  1e5 + 10;


/*
  一开始理解的有问题，arr数组并没有具体的存储树的物理结构，idx名副其实的就是索引。
*/

/* The most extreme case here is a single string of length 1e5
*  arr array stores the children of the current node
*  cnt array stores tne count of the string 
*/ 
int arr[N][26], cnt[N], idx = 0;


/*
* Function: Insert this string to Trie
*/
void Insert(string str)
{
    int p = 0;
    for (int i = 0; str[i]; ++ i)
    {
        int u = str[i] - 'a';
        if (!arr[p][u]) arr[p][u] = ++ idx;
        p = arr[p][u];
    }
    cnt[p] ++;
}

/*
* Function: Query this string in Trie
*/
int Query(string str)
{
    int p = 0;
    for (int i = 0; str[i]; ++ i)
    {
        int u = str[i] - 'a';
        if (!arr[p][u]) return 0;
        p = arr[p][u];   
    }
    return cnt[p];
}

int main()
{
    int w; cin >> w;
    string tmp;
    char op;
    
    while (w --)
    {
        cin >> op >> tmp;
        if (op == 'I')
        {
            Insert(tmp);
        } else {
            cout << Query(tmp) << endl;
        }
    }
    return 0;
}
