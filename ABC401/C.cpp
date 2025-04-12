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

ll MOD = 1000000000;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> ans;
    vector<ll> sum;
    sum.push_back(0);
    ans.push_back(0);
    rep(i, n + 1)
    {
        if(ans.size() <= k)
        {
            ans.push_back(1);
        }
        else
        {
            ll tmp = sum[sum.size() - 1] - sum[sum.size() - (k + 1)];
            tmp = (tmp % MOD + MOD) % MOD;
            ans.push_back(tmp);
        }
        ll tmp = sum[sum.size() - 1] + ans[ans.size() - 1] % MOD;
        sum.push_back(tmp);
    }
    cout << ans[n + 1] << endl;
    return 0;
}