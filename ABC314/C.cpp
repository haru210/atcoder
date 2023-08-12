#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n,m;
    string s;
    cin >> n >> m >> s;
    int c[n];
    vector<char> check[m];
    rep(i,n)
    {
        int tmp;
        cin >> tmp;
        tmp--;
        c[i] = tmp;
    }
    rep(i,n)
    {
        check[c[i]].push_back(s[i]);
    }
    string ans = "";
    int cnt[m] = {0};
    rep(i,n)
    {
        if(cnt[c[i]] == 0) ans += check[c[i]][check[c[i]].size() - 1];
        else
        {
            ans += check[c[i]][cnt[c[i]] - 1];
        }
        cnt[c[i]]++;
    }
    cout << ans << endl;
    return 0;
}