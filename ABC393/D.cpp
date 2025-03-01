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
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> op;
    rep(i, n)
    {
        if(s[i] == '1')
        {
            op.push_back(i - op.size());
        }
    }
    ll sum = 0;
    rep(i, op.size())
    {
        sum += op[i];
    }
    ll ans = sum;
    ll bsum = sum;
    ll diff = op.size();
    ll ord = 0;
    while(op[ord] == 0)
    {
        diff -= 2;
        ord++;
        if(ord == op.size()) break;
    }
    for(int i = 1; i < (n - (op.size() - 1)); i++)
    {
        ll tmp = bsum;
        tmp -= diff;
        while(op[ord] == i)
        {
            ord++;
            diff -= 2;
            if(ord == op.size()) break;
        }
        if(ans >= tmp)
        {
            ans = tmp;
            bsum = tmp;
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}