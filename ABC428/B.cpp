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
    int n, k;
    string s;
    cin >> n >> k >> s;
    map<string, int> dict;
    rep(i, n - k + 1)
    {
        string tmp = s.substr(i, k);
        dict[tmp]++;
    }
    int max_val = -1;
    vector<string> ans;
    for(auto& [key, val]: dict)
    {
        if(val >= max_val)
        {
            max_val = val;
        }
    }
    for(auto &[key, val]: dict)
    {
        if(val == max_val)
        {
            ans.push_back(key);
        }
    }
    sort(ans.begin(), ans.end());
    cout << max_val << endl;
    rep(i, ans.size()) cout << ans[i] << ' ';
    return 0;
}