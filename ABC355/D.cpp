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

int main()
{
    int n;
    cin >> n;
    int l[n], r[n];
    vector<pint> al;
    rep(i, n)
    {
        cin >> l[i] >> r[i];
        al.push_back(make_pair(l[i], 0));
        al.push_back(make_pair(r[i], 1));
    }
    sort(al.begin(), al.end());
    ll ans = 0;
    ll num = 0;
    rep(i, al.size())
    {
        if(al[i].second == 0)
        {
            ans += num;
            num++;
        }
        else
        {
            num--;
        }
    }
    cout << ans << endl;
    return 0;
}