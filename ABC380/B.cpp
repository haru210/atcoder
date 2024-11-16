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
    vector<int> ans;
    int nl = 0;
    rep(i, s.size())
    {
        if(i != 0 && s[i] == '|')
        {
            ans.push_back(nl);
            nl = 0;
        }
        else if(s[i] == '-') nl++;
    }
    rep(i, ans.size())
    {
        cout << ans[i];
        if(i != ans.size() - 1) cout << ' ';
        else cout << endl;
    }
    return 0;
}