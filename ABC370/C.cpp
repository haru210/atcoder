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

//辞書順が速くなる奴を前から->遅くなる奴を後ろから
int main()
{
    string s, t;
    vector<string> ans;
    cin >> s >> t;
    int x = 0;
    rep(i, s.size())
    {
        if(s[i] == t[i])
        {
            continue;
        }
        else
        {
            int s_num = s[i] - 'a';
            int t_num = t[i] - 'a';
            if(s_num > t_num)
            {
                s[i] = t[i];
                x++;
                ans.push_back(s);
            }
        }
    }
    for(int i = s.size() - 1; i >= 0; i--)
    {
        if(s[i] == t[i])
        {
            continue;
        }
        else
        {
            s[i] = t[i];
            x++;
            ans.push_back(s);
        }
    }
    cout << x << endl;
    rep(i, x) cout << ans[i] << endl;
    return 0;
}