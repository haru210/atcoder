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

long long powl(ll a, ll e)
{
    if(e == 0) return 1;
    ll ans = 1;
    rep(i, e)
    {
        ans *= a;
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    unsigned long long num = 1;
    rep(i, n)
    {
        ll tmp;
        cin >> tmp;
        unsigned long long num_tmp = num;
        num_tmp *= tmp;
        if(tmp >= l_inf / num) num = 1;
        else if(to_string(num_tmp).size() > k) num = 1;
        else num *= tmp;
    }
    cout << num << endl;
    return 0;
}