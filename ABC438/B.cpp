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

int main()
{
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    int ans = inf;
    rep(i, n - m + 1)
    {
        int tmp = 0;
        rep(j, m)
        {
            int sn = s[i + j] - '0';
            int tn = t[j] - '0';
            if (sn > tn) tmp += sn - tn;
            else if (sn < tn)
            {
                tmp += 10 - tn;
                tmp += sn;
            }
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
