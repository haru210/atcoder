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

//置く場所をdfsで決める、実際に埋める->imos法
//長方形なので回転は90度一つだけ考える
//和がマスの数になったタイミングで埋める

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
int n, h, w;
int a[10], b[10];
int min_myno = inf;
bool ans = false;
int grid[15][15] = {};
bool used_grid[10] = {};

bool isOk()
{
    int g_c[15][15] = {};
    rep2(i, h)
    {
        rep2(j, w) g_c[i][j] = g_c[i][j-1] + grid[i][j];
    }
    rep2(j, w)
    {
        rep2(i, h) g_c[i][j] = g_c[i-1][j] + g_c[i][j];
    }
    rep2(i,h)
    {
        rep2(j,w)
        {
            if(g_c[i][j] != 1)
            {
                return false;
            }
        }
    }
    return true;
}

void dfs(int myno, bool rolled, int sum_grid, int x, int y)
{
    if(ans) return;
    used_grid[myno] = true;
    sum_grid += a[myno] * b[myno];
    if(rolled)
    {
        grid[y][x]++;
        grid[y][x + a[myno]]--;
        grid[y + b[myno]][x]--;
        grid[y + b[myno]][x + a[myno]]++;
    }
    else
    {
        grid[y][x]++;
        grid[y][x + b[myno]]--;
        grid[y + a[myno]][x]--;
        grid[y + a[myno]][x + b[myno]]++;
    }
    if(sum_grid == h * w)
    {
        bool tmp;
        tmp = isOk();
        if(tmp)
        {
            ans = true;
            return;
        }
    }
    else if((h * w) - min_myno >= 1)
    {
        rep(i,n)
        {
            if(used_grid[i] == true) continue;
            rep2(j,h) rep2(k,w)
            {
                if(!rolled)
                {
                    if((j <= (y + a[myno] - 1)) && (k <= (x + b[myno] - 1))) continue;
                }
                else
                {
                    if((j <= (y + b[myno] - 1)) && (k <= (x + a[myno] - 1))) continue;
                }
                if(j + a[i] <= (h+1) && k + b[i] <= (w+1)) dfs(i, false, sum_grid, k, j);
                if(j + b[i] <= (h+1) && k + a[i] <= (w+1)) dfs(i, true, sum_grid, k, j);
            }
        }
    }
    if(rolled)
    {
        grid[y][x]--;
        grid[y][x + a[myno]]++;
        grid[y + b[myno]][x]++;
        grid[y + b[myno]][x + a[myno]]--;
    }
    else
    {
        grid[y][x]--;
        grid[y][x + b[myno]]++;
        grid[y + a[myno]][x]++;
        grid[y + a[myno]][x + b[myno]]--;

    }
    used_grid[myno] = false;
    sum_grid -= a[myno] * b[myno];
}

int main()
{
    cin >> n >> h >> w;
    int al = 0;
    rep(i,n) 
    {
        cin >> a[i] >> b[i];
        al += a[i] * b[i];
        min_myno = min(min_myno, a[i] * b[i]);
    }
    if(al < h * w) cout << "Np\n";
    else 
    {
        rep(i,n)
        {
            rep(j,12) rep(k,12) grid[i][j] = 0;
            rep2(j,h) rep2(k,w)
            {
                if(j + b[i] <= (h+1) && k + a[i] <= (w+1)) dfs(i, true, 0, k, j);
                if(j + a[i] <= (h+1) && k + b[i] <= (w+1)) dfs(i, false, 0, k, j);
            }
        }
        YesNo(ans);
    }
    return 0;
}