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
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}
pll a[200000];
ll sum[200000] = {0};
int main()
{
    ll n;
    cin >> n;
    rep(i,n)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a,a+n);
    sum[n-1] = 0;
    ll chain = a[n-1].first;
    for(ll i = n-2; i >= 0; i--)
    {
        if(a[i].first == a[i+1].first)
        {
            chain += a[i].first;
            sum[i] = sum[i+1];
        }
        else
        {
            sum[i] = chain;
            chain += a[i].first;
        }
    }
    rep(i,n)
    {
        a[i].first = sum[i];
    }
    sort(a, a+n, compare);
    rep(i,n-1) cout << a[i].first <<' ';
    cout << a[n-1].first << endl;
    return 0;
}