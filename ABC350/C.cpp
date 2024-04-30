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
    cin >> n;
    int a[n+1];
    int pl[n+1] = {};
    vector<pint> ans;
    rep2(i,n)
    {
        cin >> a[i];
        pl[a[i]] = i;
    }
    rep2(i, n-1)
    {
        int sn = pl[i]; //sn := iがある場所
        if(i == sn) continue;
        ans.push_back({i, sn});
        swap(pl[a[i]], pl[a[sn]]);
        swap(a[i], a[sn]);
    }
    cout << ans.size() << endl;
    rep(i,ans.size())
    {
        if(ans[i].first > ans[i].second) swap(ans[i].first, ans[i].second);
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}