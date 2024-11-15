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
    ll dig_times[n + 1];
    rep2(i, n)
    {
        dig_times[i] = (int)(s[i - 1] - '0') * (i);
    }
    ll sum[n + 1];
    sum[0] = 0;
    rep2(i, n)
    {
        sum[i] = sum[i - 1] + dig_times[i];
    }
    vector<ll> ans;
    ll carry = 0;
    rep2(i, n)
    {
        ll tmp = sum[n - (i - 1)];
        tmp += carry;
        ans.push_back(tmp % 10);
        tmp /= 10;
        carry = tmp;
    }
    while(carry > 0)
    {
        ans.push_back(carry % 10);
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());
    rep(i, ans.size())
    {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}