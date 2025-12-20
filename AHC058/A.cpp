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

const int c_size = 15;
const int c_start = 500 - ((c_size + 1) * 10);
//上の層作った方が良いだろうが教教祖です
int main()
{
    int n, l, t, ak;
    cin >> n >> l >> t >> ak;
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
    ll pc[c_size][l][n] = {};
    ll bc[c_size][l][n] = {};
    ll apples_c[c_size] = {};
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
            pll gre_mach = {-1, -1};
            ll gre_prof = -1;
            rep(j, l)
            {
                rep(k, n)
                {
                    if(apples > cost[j][k])
                    {
                        able_mach = {j, k};
                        if(gre_mach.first < j)
                        {
                            gre_mach = {j, k};
                            if(gre_mach.first == 0)
                            {
                                gre_prof = a[k] * b[j][k] * (p[j][k] + 1);
                            }
                            else
                            {
                                gre_prof = b[j][k] * (p[j][k] + 1);
                            }
                        }
                        else if(gre_mach.first == j)
                        {
                            if(gre_mach.first == 0 && gre_prof < (a[k] * b[j][k] * (p[j][k] + 1)))
                            {
                                gre_mach = {j, k};
                                gre_prof = a[k] * b[j][k] * (p[j][k] + 1);
                            }
                            else if(gre_prof < (b[j][k] * (p[j][k] + 1)))
                            {
                                gre_mach = {j, k};
                                gre_prof = b[j][k] * (p[j][k] + 1);
                            }
                        }
                    }
                }
            }
            if(gre_mach.first == -1 && gre_mach.second == -1)
            {
                ans.push_back(to_string(-1));
            }
            else
            {
                int tmpi = gre_mach.first;
                int tmpj = gre_mach.second;
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
        rep(j, c_size)
        {
            if(i == (c_start + (j * 10)))
            {
                apples_c[j] = apples;
                rep(ti, l)
                {
                    rep(tj ,n)
                    {
                        bc[j][ti][tj] = b[ti][tj];
                        pc[j][ti][tj] = p[ti][tj];
                    }
                }
            }
            if(i > (c_start + j * 10))
            {
                rep(ti, l)
                {
                    rep(tj, n)
                    {
                        if(j == 0)
                        {
                            apples_c[j] += a[tj] * bc[j][ti][tj] * pc[j][ti][tj];
                        }
                        else
                        {
                            bc[j][ti - 1][tj] += bc[j][ti][tj] * pc[j][ti][tj];
                        }
                    }
                }
            } 
        }
    }
    ll ap_max = -1;
    ll ap_maxi = -1;
    rep(i, c_size)
    {
        if(ap_max < apples_c[i])
        {
            ap_max = apples_c[i];
            ap_maxi = i;
        }
    }
    if(apples < ap_max)
    {
        rep(i, ans.size())
        {
            if(i < (c_start + 10 * ap_maxi))cout << ans[i] << endl;
            else cout << -1 << endl;
        }
    }
    else rep(i, ans.size()) cout << ans[i] << endl;
    return 0;
}