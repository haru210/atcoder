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

//クエリをそれぞれO(1)かO(logN)で
//要素数を取得できるunion-findを使う、色はクエリ1のたびに計算する

struct union_find 
{
    vector<int> par;
    vector<int> g_sizes; //その点が親なら要素数を  
    vector<int> l_sides; //その点が親なら左端を
    vector<int> r_sides; //その点が親なら右端を

    union_find(int n) : par(n), g_sizes(n, 1), l_sides(n), r_sides(n)
    {
        rep(i,n) 
        {
            par[i] = i;
            l_sides[i] = i;
            r_sides[i] = i;
        }
    }
    int root(int x)
    {
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void unite(int a, int b) //aを親として統合
    {
        int ra = root(a);
        int rb = root(b);
        if(ra == rb) return;
        par[rb] = ra;
        if(r_sides[ra] < l_sides[rb])
        {
            r_sides[ra] = r_sides[rb];
        }
        else
        {
            l_sides[ra] = l_sides[rb];
        }
        g_sizes[ra] += g_sizes[rb];
    }
    bool same(int a, int b)
    {
        if(root(a) == root(b)) return true;
        else return false;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    union_find ut(n);
    vector<int> p_col(n);
    vector<int> col_cnt(n, 1);
    rep(i, n) p_col[i] = i;
    rep(i, q)
    {
        int que;
        cin >> que;
        if(que == 1)
        {
            int x, c;
            cin >> x >> c;
            x--;
            c--;
            int rtx = ut.root(x);
            int xl = ut.l_sides[rtx]; //xの左端
            int xr = ut.r_sides[rtx]; //xの右端
            int rtl; //xの左要素の親
            int rtr;  //xの右要素の親
            col_cnt[p_col[rtx]] -= ut.g_sizes[rtx];
            col_cnt[c] += ut.g_sizes[rtx];
            p_col[rtx] = c;
            if(xl != 0)
            {
                rtl = ut.root(xl - 1);
                if(c == p_col[rtl])
                {
                    ut.unite(rtx, rtl);
                }
            } 
            if(xr != n - 1)
            {
                rtr = ut.root(xr + 1);
                if(c == p_col[rtr])
                {
                    ut.unite(rtx, rtr);
                }
            }
        }
        if(que == 2)
        {
            int c;
            cin >> c;
            c--;
            cout << col_cnt[c] << endl;
        }
    }
    return 0;
}