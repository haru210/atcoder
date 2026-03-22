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
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    vector<vector<bool>> ch_cnt(26, vector<bool>(n, false));
    rep(i, n)
    {
        ch_cnt[(s[i] - 'a')][i] = true;
    }
    ll ans = 0;
    rep(i, 26)
    {
        int cnt = 0;
        for (int j = l; j <= r; j++)
        {
            if (ch_cnt[i][j]) cnt++;
        }
        for (int j = 0; j < n - l; j++)
        {
            if ((s[j] - 'a') == i)
            {
                ans += cnt;
            }
            if (ch_cnt[i][j + l])
            {
                cnt--;
            }
            if (j + r + 1 >= n) continue;
            if (ch_cnt[i][j + r + 1]) cnt++;
        }
    }
    cout << ans << endl;
    return 0;
}
