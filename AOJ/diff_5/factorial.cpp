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
void prime_factorize(vector<pll>& res, ll a)
{
    for(ll i = 2; i * i <= a;i++)
    {
        if(a % i != 0) continue;
        ll ex = 0;
        while(a % i == 0)
        {
            a /= i;
            ex++;
        }
        res.push_back(make_pair(i,ex));
    }
    if(a != 1) res.push_back(make_pair(a,1));
}
ll how_many(ll n, ll p)
{
    ll ex = 0;
    while(n %p == 0)
    {
        n /= p;
        ex++;        
    }
    return ex;
}
//nを素因数分解後、各素因数についてn!の最小値を求める
//素因数pはnがpの倍数であるときしか増えないので、i+=pで遷移
//それぞれの素因数の最大値をとればよい(階乗なので、それ以下の数字は含んでいるので)
int main()
{
    ll n;
    ll ans = 1;
    cin >> n;
    vector<pll> pf;
    prime_factorize(pf, n);
    for(auto [n, p]:pf) //各素因数に関して
    {
        ll tmp = 0;
        for(ll i = n;; i += n)
        {
            tmp += how_many(i, n);
            if(tmp >= p)
            {
                ans = max(ans, i);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}