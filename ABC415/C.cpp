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


//同じ薬品を違う順番で入れると同じ状態になるのでメモ化再帰できる
bool ok = false;
void dfs(string& s, int picked, int n, vector<bool>& tried)
{
    rep(i, n)
    {
        if(!(picked & (1 << i))) //i番目の薬品を選んでいないなら選ぶ
        {
            picked += (1 << i);
            if(tried[picked]) 
            {
                picked -= (1 << i);
                continue;
            }
            if(s[picked - 1] == '0')
            {
                if(picked == (1 << n) - 1)
                {
                    ok = true;
                    return;
                }
                tried[picked] = true;
                dfs(s, picked, n, tried);
                if(ok) return;
            }
            picked -= (1 << i);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    rep(cs, t)
    {
        int n;
        string s;
        ok = false;
        cin >> n >> s;
        vector<bool> tried((1 << n), false);
        if(s[(1 << n) - 1] == '1')
        {
            cout << "No\n";
            continue;
        }
        dfs(s, 0, n, tried);
        YesNo(ok);
    }
    return 0;
}