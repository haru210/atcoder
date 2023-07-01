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
    map<int,int> a;
    rep(i, 2*n - 1)
    {
        int tmp;
        cin >> tmp;
        a[tmp]++;
    }
    rep(i, n + 1)
    {
        if(a[i] == 1)
        {
            cout << i << endl;
        }
    }
    return 0;
}