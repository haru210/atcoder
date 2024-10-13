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
    int n, m;
    cin >> n >> m;
    string s[n];
    int ans = inf;
    rep(i, n) cin >> s[i];
    for(int i = 0; i < (1 << n); i++)
    {
        bool ok[m] = {};
        int cnt = 0;
        rep(j, n)
        {
            if(!(i & (1 << j))) continue;
            cnt++;
            rep(k, m)
            {
                if(s[j][k] == 'o') ok[k] = true;
            }
            bool al = true;
            rep(k, m)
            {
                if(!ok[k]) al = false;
            }
            if(al) ans = min(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}