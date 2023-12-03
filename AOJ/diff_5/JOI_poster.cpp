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
string ans = "";
int n,k;
void dfs(ll width, int line)
{
    if(width == 1 && line == 1)
    {
        ans += 'J';
        return;
    }
    if(width / 2 >= line)
    {
        rep2(i,width / 2) ans += 'J';
        rep2(i,width / 2) ans += 'O';
        return;
    }
    else
    {
        rep2(i,width / 2) ans += 'I';
        ll next_width = width / 2;
        dfs(next_width, line - next_width);
    }
}
int main()
{
    cin >> n >> k;
    ll width = 1;
    rep(i,n) width *= 2;
    //正方形の上半分なら半分までJ,半分からO
    //下半分なら半分までIで、半分からもう一度再帰的に
    dfs(width, k);
    cout << ans << endl;
    return 0;
}