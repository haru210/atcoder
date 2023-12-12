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
    int n,x;
    int ans = 0;
    cin >> n >> x;
    int s[n];
    rep(i,n) cin >> s[i];
    rep(i,n)
    {
        if(s[i] <= x) ans += s[i]; 
    }
    cout << ans  << endl;
    return 0;
}