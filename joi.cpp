#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    cin >> n;
    int a[n]={0};
    for(int i = 0; i < 2 * n - 1;i++)
    {
        int tmp;
        cin >> tmp;
        tmp--;
        a[tmp]++;
    }
    rep(i, n)
    {
        if(a[i] == 1)
        {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}