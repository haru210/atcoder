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
    int ans = 0;
    cin >> n;
    long double t[n], l[n], r[n];
    rep(i,n)
    {
        cin >> t[i] >> l[i] >> r[i];
        if(t[i] == 3 || t[i] == 4) l[i] += 0.5;
        if(t[i] == 2 || t[i] == 4) r[i] -= 0.5;
    }
    rep(i,n)
    {
        rep(j,n)
        {
            if(i >= j) continue;
            if(max(l[i], l[j]) <= min(r[i], r[j])) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}