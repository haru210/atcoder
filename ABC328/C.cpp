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
    int n,q;
    string s;
    cin >> n >> q >> s;
    int l[q],r[q];
    rep(i,q)
    {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
    }
    int cnt[n+1];
    cnt[0] = 0;
    rep2(i,n)
    {
        cnt[i] = cnt[i-1];
        if(s[i] == s[i-1]) cnt[i]++;
    }
    rep(i,q)
    {
        cout << cnt[r[i]] - cnt[l[i]-1] << endl;
    }
    return 0;
}