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
    int n;
    ll ans = 0;
    cin >> n;
    string s[n];
    rep(i,n) cin >> s[i];
    //各oに対してそれが曲がり角になるLの個数を数える
    //各oに対して(その行にあるoの数-1)x(その列にあるoの数-1)がLの個数(それ自体を選べないので1引く)
    ll row[n] = {}; //rowと行で韻が踏めるので行
    ll column[n] = {};  //行じゃないので列
    rep(i, n){
        rep(j, n)
        {
            if(s[i][j] == 'o')
            {
                row[i]++;
                column[j]++;
            }
        }
    }
    rep(i,n)
    {
        rep(j,n)
        {
            if(s[i][j] == 'x') continue;
            ans += (row[i] - 1) * (column[j] - 1);
        }
    }
    cout << ans << endl;
    return 0;
}