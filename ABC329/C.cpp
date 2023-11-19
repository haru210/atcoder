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
    ll ans = 0;
    string s;
    cin >> n >> s;
    int al_cnt[26] = {0};
    vector<string> cuted;
    //各文字について最も長い連続部分を求める
    string tmp = "";
    tmp += s[0];
    for(int i = 1; i < n; i++)
    {
        if(s[i] != s[i-1])
        {
            cuted.push_back(tmp);
            tmp = "";
        }
        tmp += s[i];
    }
    cuted.push_back(tmp);
    rep(i,cuted.size())
    {
        int al = cuted[i][0] - 'a';
        al_cnt[al] = max(al_cnt[al], (int)cuted[i].size());
    }
    rep(i,26)
    {
        ans += al_cnt[i];
    }
    cout << ans << endl;
    return 0;
}