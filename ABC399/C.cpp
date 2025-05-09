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
    //union-find木で既に連結であるところに引く辺を消去すればよい
    int n, m;
    cin >> n >> m;
    union_find uf(n);
    int ans = 0;
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if(uf.same(u, v)) ans++;
        else uf.unite(u, v);
    }
    cout << ans << endl;
    return 0;
}