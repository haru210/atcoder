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

ll power(int a, int e)
{
    ll s = 1;
    rep(i,e)
    {
        s *= a;
    }
    return s;
}
int main()
{
    int n;
    cin >> n;
    int m = 1;
    bool flag = false;
    for(int i = 1;; i++)
    {
        ll tmp = power(2, i);
        if(tmp >= n)
        {
            m = i;
            break;
        }
    }
    cout << m << endl;
    rep(i,m)
    {
        vector<int> dr;
        rep(j,n)
        {
            if(j & (1 << i))
            {
                dr.push_back(j+1);
            }
        }
        cout << dr.size() << ' ';
        rep(i,dr.size()-1) cout << dr[i] << ' ';
        cout << dr[dr.size()-1] << endl;
    }
    string res;
    cin >> res;
    int ans = 0;
    rep(i,res.size())
    {
        if(res[i] == '1')
        {
            ans += power(2, i);
        }
    }
    cout << ans + 1 << endl;
    return 0;
}