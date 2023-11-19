#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
ll power(int num)
{
    ll ans = 1;
    rep(i, num)
    {
        ans *= (ll)num;
    }
    return ans;
}
int main()
{
    ll b;
    bool ok = false;
    cin >> b;
    for(int i = 1; power(i) <= b; i++)
    {
        if(power(i) == b)
        {
            cout << i << endl;
            ok = true;
            break;
        }
    }
    if(!ok) cout << -1 << endl;
    return 0;
}