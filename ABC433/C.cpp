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
    string s;
    cin >> s;
    vector<pint> ran_len;
    int now = -1;
    int length = 0;
    rep(i, s.size())
    {
        if((s[i] - '0') != now)
        {
            if(now != -1)
            {
                ran_len.push_back({now, length});
            }
            now = s[i] - '0';
            length = 1;
        }
        else
        {
            length++;
        }
    }
    ran_len.push_back({now, length});
    ll ans = 0;
    rep(i, ran_len.size() - 1)
    {
        if(ran_len[i].first + 1 == ran_len[i + 1].first)
        {
            ans += min(ran_len[i].second, ran_len[i + 1].second);
        }
    }
    cout << ans << endl;
    return 0;
}