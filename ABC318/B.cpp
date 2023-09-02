#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    cin >> n;
    int a[n],b[n],c[n],d[n];
    ll ans = 0;
    rep(i,n)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    rep(i,101)
    {
        rep(j,101)
        {
            rep(k,n)
            {
                if(i >= c[k] && i < d[k] && j >= a[k] && j < b[k])
                {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}