#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

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
    bool a[n];
    int on_cnt[n]; //左端からi番目の得する数
    int max_first = 0;
    int max_index = -1;
    rep(i,n) cin >> a[i];
    if(a[0]) on_cnt[0] = 1;
    else on_cnt[0] = -1;
    if(max_first < on_cnt[0])
    {
        max_first = on_cnt[0];
        max_index = 0; 
    }
    rep2(i,n-1)
    {
        if(a[i]) on_cnt[i] = on_cnt[i-1] + 1;
        else on_cnt[i] = on_cnt[i-1] - 1;
        if(max_first < on_cnt[i])
        {
            max_first = on_cnt[i];
            max_index = i;
        }
    }
    int ans = 0;
    rep(i,n)
    {
        if(i <= max_index)
        {
            if(!a[i]) ans++;
        }
        else
        {
            if(a[i]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}