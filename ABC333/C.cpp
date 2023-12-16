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
ll next_num(int level)
{
    ll tmp = 0;
    ll e = 1;
    rep(i,level)
    {
        tmp += e;
        e *= 10;
    }
    return tmp;
}
int main()
{
    int n;
    cin >> n;
    ll s[14];
    map<ll,int> num;
    rep2(i,13) s[i] = next_num(i);
    rep2(i,13)
    {
        rep2(j,13)
        {
            rep2(k,13)
            {
                ll tmp = s[i] + s[j] + s[k];
                num[tmp]++;
            }
        }
    }
    int cnt = 1;
    for(auto [key,val]: num)
    {
        if(cnt == n)
        {
            cout << key << endl;
            break;
        }
        cnt++;
    }
    return 0;
}