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
    string s[n];
    string t[n];
    rep(i, n)
    {
        cin >> s[i];
    }
    rep(i, n)
    {
        cin >> t[i];
    }
    char rot[4][n][n];
    rep(i, n)
    {
        rep(j, n)
        {
            rot[0][i][j] = s[i][j];
        }
    }
    rep(i, n)
    {
        rep(j, n)
        {
            rot[1][i][j] = s[n - j - 1][i];
        }
    }
    rep(i, n)
    {
        rep(j, n)
        {
            rot[2][i][j] = rot[1][n - j - 1][i];
        }
    }
    rep(i, n)
    {
        rep(j, n)
        {
            rot[3][i][j] = rot[2][n - j - 1][i];
        }
    }
    int ans = inf;
    rep(i, 4)
    {
        int tmp = 0;
        rep(j, n)
        {
            rep(k, n)
            {
                if(rot[i][j][k] != t[j][k])
                {
                    tmp++;
                }
            }
        }
        tmp += i;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}