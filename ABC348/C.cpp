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
    map<int,int> min_val;
    rep(i,n)
    {
        int a,c;
        cin >> a >> c;
        int now_min = min_val[c];
        if(now_min == 0 || now_min > a)
        {
            min_val[c] = a;
        }
    }
    int ans = 0;
    for(auto& [key,val] : min_val)
    {
        if(val == 0) continue;
        if(ans < val) ans = val;
    }
    cout << ans << endl;
    return 0;
}