#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    int n, m;
    cin >> n >> m;
    ll a[n];
    ll b[m];
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    ll sum = 0;
    sort(a, a + n);
    sort(b, b + m);
    ll ap = 0;
    bool ok = true;
    rep(i, m)
    {
        if(ap >= n)
        {
            ok = false;
            break;
        }
        while(a[ap] < b[i])
        {
            ap++;
            if(ap >= n)
            {
                ok = false;
                break;
            }
        }
        if(!ok) break;
        sum += a[ap];
        ap++;
    }
    if(!ok) cout << -1 << endl;
    else cout << sum << endl;
    return 0;
}