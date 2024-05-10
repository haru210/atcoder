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
    int h, w, k;
    cin >> h >> w >> k;
    string s[h];
    rep(i, h) cin >> s[i];
    ll orow[h+1][w+1] = {};
    ll ocolumn[w+1][h+1] = {};
    rep2(i, h)
    {
        rep2(j, w)
        {
            orow[i][j] = orow[i][j-1];
            ocolumn[j][i] = ocolumn[j][i-1];
            if(s[i-1][j-1] == 'o')
            {
                orow[i][j]++;
                ocolumn[j][i]++;
            }
            if(s[i-1][j-1] == 'x')
            {
                orow[i][j]-= 1000000;
                ocolumn[j][i] -= 1000000;
            }
        }
    }
    ll ans = l_inf;
    rep2(i, h)
    {
        rep2(j, (w- k + 1))
        {
            ll tmp = orow[i][j + k - 1] - orow[i][j - 1];
            if(tmp < 0) continue;
            tmp = k - tmp;
            ans = min(tmp, ans);
        }
    }
    rep2(j, w)
    {
        rep2(i, (h - k + 1))
        {
            ll tmp = ocolumn[j][i + k - 1] - ocolumn[j][i-1];
            if(tmp < 0) continue;
            tmp = k - tmp;
            ans = min(tmp, ans);
        }
    }
    if(ans == l_inf) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}