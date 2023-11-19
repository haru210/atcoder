#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int a[9][9];
    bool ans = true;
    rep(i,9) rep(j,9)
    {
        int tmp;
        cin >> tmp;
        tmp--;
        a[i][j] = tmp;
    }
    bool line[9][9] = {false}; //行
    bool column[9][9] = {false}; //列
    bool block[9][9] = {false};
    //重複していたら何かが重なる=何かが足りないので、すべてあることだけ判定すればよい
    rep(i,9)
    {
        rep(j,9)
        {
            line[i][a[i][j]] = true;
            column[j][a[i][j]] = true;
        }
    }
    bool ok = true;
    rep(i,9)
    {
        rep(j,9)
        {
            if(!line[i][j]) ok = false;
            if(!column[i][j])ok = false;
        }
    }
    if(!ok) ans = false;
    int dx = 0;
    int dy = 0;
    rep(i,9)
    {
        rep(j,3)
        {
            rep(k,3)
            {
                block[i][a[j+dx][k+dy]] = true;
            }
        }
        if(dx != 6) dx += 3;
        else
        {
            dx = 0;
            dy += 3;
        }
    }
    ok = true;
    rep(i,9)
    {
        rep(j,9)
        {
            if(!block[i][j]) ok = false;
        }
    }
    if(!ok) ans = false;
    YesNo(ans);
    return 0;
}