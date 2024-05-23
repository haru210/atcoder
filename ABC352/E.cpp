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

struct union_find 
{
    vector<int> par;

    union_find(int n) : par(n)
    {
        rep(i,n) par[i] = i;
    }
    int root(int x)
    {
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void unite(int a, int b)
    {
        int ra = root(a);
        int rb = root(b);
        if(ra == rb) return;
        par[ra] = rb;
    }
    bool same(int a, int b)
    {
        if(root(a) == root(b)) return true;
        else return false;
    }
};
int main()
{
    int n,m;
    cin >> n >> m;
    int k[m], c[m];
    vector<vector<int>> a(m);
    vector<tuple<int, int, int>> g;
    rep(i, m)
    {
        cin >> k[i] >> c[i];
        rep(j, k[i])
        {
            int tmp;
            cin >> tmp;
            tmp--;
            a[i].push_back(tmp);
        }
    }
    rep(i, m)
    {
        rep2(j, k[i] - 1)
        {
            g.push_back({c[i], a[i][0], a[i][j]});
        }
    }
    sort(g.begin(), g.end());
    union_find ut(n);
    ll sum = 0;
    ll cnt = 0;
    rep(i, g.size())
    {
        if(ut.same(get<1>(g[i]), get<2>(g[i])) == false)
        {
            ut.unite(get<1>(g[i]), get<2>(g[i]));
            sum += get<0>(g[i]);
            cnt++;
        }
        if(cnt >= n) break;
    }
    if(cnt < n - 1) cout << -1 << "\n";
    else cout << sum << "\n";
    return 0;
}