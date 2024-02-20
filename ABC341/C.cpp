#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

int main()
{
    int h,w,n;
    int ans = 0;
    cin >> h >> w >> n;
    string t;
    string s[h];
    vector<pint> g_dic;
    cin >> t;
    rep(i,h)
    {
        cin >> s[i];
    }
    rep(i,h-1)
    {
        rep(j,w-1)
        {
            if(i == 0 || h == 0) continue;
            if(s[i][j] == '#') continue;
            bool ok = true;
            int y = i;
            int x = j;
            rep(k,n)
            {
                switch(t[k])
                {
                    case 'L':
                    x--;
                    break;
                    case 'R':
                    x++;
                    break;
                    case 'U':
                    y--;
                    break;
                    case 'D':
                    y++;
                    break;
                }
                if(s[y][x] == '#')
                {
                    ok = false;
                    break;
                }
            }
            if(ok) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}