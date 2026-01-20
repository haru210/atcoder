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
    int n;
    string s;
    cin >> n >> s;
    vector<int> diff(n + 1, 0);
    diff[0] = 0;
    rep2(i, n)
    {
        diff[i] = diff[i - 1];
        if (s[i - 1] == 'A')
        {
            diff[i]++;
        }
        if (s[i - 1] == 'B')
        {
            diff[i]--;
        }
    }
    vector<int> tmp = diff;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    vector<int> diff_p(n + 1);
    rep(i, n + 1)
    {
        diff_p[i] = lower_bound(tmp.begin(), tmp.end(), diff[i]) - tmp.begin();
        diff_p[i]++; //BITに0が入ると面倒
    }
    //BITを用いて、iより右側のうち自分より大きい数を探す->iより左側の内自分より小さい数を探す
    //座圧したので、0～N-1までの値しか入っていない
    vector<ll> bit(n + 5, 0);
    ll ans = 0;
    rep(i, n + 1)
    {
        int pos = diff_p[i];
        while (pos <= n)
        {
            bit[pos]++;
            pos += (pos & -pos);
        }
        pos = diff_p[i] - 1; //diff_p[i]未満の数を探索する
        ll sum = 0;
        while (pos > 0)
        {
            sum += bit[pos];
            pos -= (pos & -pos);
        }
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}
