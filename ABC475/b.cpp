#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int change[3] = {};
    rep(i, n) cin >> a[i];
    rep(i, n)
    {
        int th_change = ((a[i] + 999) / 1000)* 1000 - a[i];
        change[2] += th_change / 100;
        change[1] += (th_change - ((th_change / 100) * 100)) / 10;
        change[0] += th_change % 10;
    }
    cout << change[0] << ' ' << change[1] << ' ' << change[2] << endl;
    return 0;
}
