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
    int n, m, k;
    cin >> n >> m >> k;
    int c[m];
    vector<vector<int>> a(m);
    char r[m];
    rep(i, m)
    {
        cin >> c[i];
        rep(j, c[i])
        {
            int tmp;
            cin >> tmp;
            tmp--;
            a[i].push_back(tmp);
        }
        cin >> r[i];
    }
    int ans = 0;
    rep(i, 1 << n)
    {
        bool ok = true;
        rep(j, m)
        {
            int sum = 0;
            rep(k, a[j].size())
            {
                if(i & (1 << a[j][k]))
                {
                    sum++;
                }
            }
            if(r[j] == 'o')
            {
                if(sum < k) ok = false;
            }
            else
            {
                if(sum >= k) ok = false;
            }
            if(!ok) break;
        }
        if(ok) ans++;
    }
    cout << ans << endl;
    return 0;
}