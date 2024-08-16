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

const ll m = 1000000007;
int main()
{
    int n;
    cin >> n;
    int c[n];
    rep(i, n) cin >> c[i];
    sort(c, c + n);
    bool ok = true;
    rep(i, n)
    {
        c[i] -= i;
        if(c[i] <= 0) ok = false;
    }
    if(ok)
    {
        ll sum = 1;
        rep(i, n)
        {
            sum *= c[i];
            sum %= m;
        }
        cout << sum << endl;
    }
    else cout << 0;
    return 0;
}