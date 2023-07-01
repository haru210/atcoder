#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n, m;
    ll sum = 0;
    cin >> n >> m;
    string c[n];
    string d[m];
    map<string,int> price;
    rep(i, n) cin >> c[i];
    rep(i, m) cin >> d[i];
    int other;
    cin >> other;
    rep(i, m)
    {
        int tmp;
        cin >> tmp;
        price[d[i]] = tmp;
    }
    rep(i, n)
    {
        if(price[c[i]] == 0)
        {
            sum += other;
        }
        else
        {
            sum += price[c[i]];
        }
    }
    cout << sum << endl;
    return 0;
}