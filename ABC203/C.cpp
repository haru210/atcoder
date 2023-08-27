#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    ll k;
    ll now = 0;
    cin >> n >> k;
    pair<ll,ll> friends[n];
    rep(i,n)
    {
        cin >> friends[i].first >> friends[i].second;
    }
    sort(friends,friends + n);
    rep(i,n)
    {
        if(friends[i].first - now <= k)
        {
            k -= friends[i].first - now;
            k += friends[i].second;
            now = friends[i].first;
        }
        else
        {
            break;
        }
    }
    now += k;
    cout << now << endl;
    return 0;
}