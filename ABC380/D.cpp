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
    vector<ll> pow_len;
    ll v = s.size();
    vector<char> ans;
    while(v <= 1000000000000000000)
    {
        pow_len.push_back(v);
        v *= 2;
    }
    int q;
    cin >> q;
    rep(i, q)
    {
        ll k;
        cin >> k;
        k--;
        ll ccnt = 0;
        while(k >= s.size())
        {
            ll tmp = upper_bound(pow_len.begin(), pow_len.end(), k) - pow_len.begin();
            tmp--;
            k -= pow_len[tmp];
            ccnt++;
        }
        if(ccnt % 2 == 1)
        {
            if('a' <= s[k] && s[k] <= 'z') ans.push_back(toupper(s[k]));
            if('A' <= s[k] && s[k] <= 'Z') ans.push_back(tolower(s[k]));
        }
        else
        {
            ans.push_back(s[k]);
        }
    } 
    rep(i, ans.size())
    {
        cout << ans[i];
        if(i != ans.size() - 1) cout << ' ';
        else cout << endl; 
    }
    return 0;
}