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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> b = a;
    sort(b.begin(), b.end());
    ll p1 = k % n;
    rep(i, n)
    {
        ll id = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        ll tmp = k / n;
        if(id < p1) tmp++;
        cout << tmp << "\n";
    }
    return 0;
}