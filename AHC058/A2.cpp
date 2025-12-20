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

//上の層作った方が良いだろうが教教祖です
int main()
{
    int n, l, t, k;
    cin >> n >> l >> t >> k;
    ll a[n];
    ll c[l][n];
    rep(i, n) cin >> a[i];
    rep(i, l)
    {
        rep(j, n) cin >> c[i][j];
    }
    ll apples = 1;
    ll cost[l][n] = {};
    ll p[l][n] = {};
    ll b[l][n] = {};
    ll pc[l][n] = {};
    ll bc[l][n] = {};
    ll apples_c = 0;
    rep(i, l)
    {
        rep(j, n)
        {
            b[i][j] = 1;
            cost[i][j] = c[i][j]; 
        }
    }
    pll back_choice = {-1, -1};
    vector<string> ans;
    rep(i, t)
    {
        if(i == 0)
        {
            ans.push_back("0 0");
            p[0][0] = 1;
            cost[0][0] = c[0][0] * (p[0][0] + 1);
            apples = 0;
        }
        else
        {
            pll able_mach = {-1, -1};
            rep(j, l)
            {
                rep(k, n)
                {
                    if(apples > cost[j][k])
                    {
                        able_mach = {j, k};
                    }
                }
            }
            if(able_mach.first == -1 && able_mach.second == -1)
            {
                ans.push_back(to_string(-1));
            }
            else
            {
                int tmpi = able_mach.first;
                int tmpj = able_mach.second;
                apples -= cost[tmpi][tmpj];
                ans.push_back(to_string(tmpi) + ' ' + to_string(tmpj));
                p[tmpi][tmpj]++;
                cost[tmpi][tmpj] = c[tmpi][tmpj] * (p[tmpi][tmpj] + 1);
                back_choice = able_mach;
            }
        }
        rep(j, l)
        {
            rep(k, n)
            {
                if(j == 0)
                {
                    apples += a[k] * b[j][k] * p[j][k];
                }
                else
                {
                    b[j - 1][k] += b[j][k] * p[j][k];
                }
            }
        }
        if(i == 400)
        {
            apples_c = apples;
            rep(j, l)
            {
                rep(k ,n)
                {
                    bc[j][k] = b[j][k];
                    pc[j][k] = p[j][k];
                }
            }
        }
        if(i > 400)
        {
            rep(j, l)
            {
                rep(k, n)
                {
                    if(j == 0)
                    {
                        apples_c += a[k] * bc[j][k] * pc[j][k];
                    }
                    else
                    {
                        bc[j - 1][k] += bc[j][k] * pc[j][k];
                    }
                }
            }
        }
    }
    if(apples < apples_c)
    {
        rep(i, ans.size())
        {
            if(i <= 400)cout << ans[i] << endl;
            else cout << -1 << endl;
        }
    }
    else rep(i, ans.size()) cout << ans[i] << endl;
    return 0;
}